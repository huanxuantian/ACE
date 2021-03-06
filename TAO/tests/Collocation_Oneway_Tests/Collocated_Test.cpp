// $Id: Collocated_Test.cpp 91825 2010-09-17 09:10:22Z johnnyw $
#include "Server_Task.h"
#include "Client_Task.h"
#include "ace/Get_Opt.h"
#include "ace/Argv_Type_Converter.h"
#include "ace/SString.h"
#include "ace/Manual_Event.h"

const ACE_TCHAR *output = ACE_TEXT("test.ior");
const ACE_TCHAR *input = ACE_TEXT("file://test.ior");
const ACE_TCHAR *mode = ACE_TEXT("SYNC_NONE");

Client_Task::ClientSyncModeEnum syncMode = Client_Task::MODE_NONE;

// static int named_orbs = 0;
ACE_CString server_orb;
ACE_CString client_orb;
int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("k:o:n:m:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'o':
        output = get_opts.opt_arg ();
        break;
      case 'k':
        input = get_opts.opt_arg ();
        break;
      case 'n':
        // named_orbs = 1;
        server_orb.set ("server_orb");
        client_orb.set ("client_orb");
        break;
      case 'm':
        mode = get_opts.opt_arg ();
        // cout << "mode = " << mode << endl;
        ACE_DEBUG ((LM_DEBUG, "(%P|%t) - mode set to <%C> for collocated oneway test\n", mode));
        if(mode) {
             if(!ACE_OS::strcmp(ACE_TEXT("none"), mode)) {
                syncMode = Client_Task::MODE_NONE;
             }
             else if (!ACE_OS::strcmp(ACE_TEXT("transport"), mode)) {
                syncMode = Client_Task::MODE_TRANSPORT;
             }
             else if (!ACE_OS::strcmp(ACE_TEXT("server"), mode)) {
                syncMode = Client_Task::MODE_SERVER;
             }
             else if (!ACE_OS::strcmp(ACE_TEXT("target"), mode)) {
                syncMode = Client_Task::MODE_TARGET;
             }
          }
          else {
             // same hack used in original test!
             return 0;
          }
        break;
      case '?':
      default:
        // This is a hack but that is okay!
        return 0;
      }
  // Indicates successful parsing of the command line
  return 0;
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  if (parse_args (argc,
                  argv) == -1)
    return -1;

  try
    {
      ACE_Argv_Type_Converter satc (argc, argv);
      CORBA::ORB_var sorb =
        CORBA::ORB_init (satc.get_argc (),
                         satc.get_TCHAR_argv (),
                         server_orb.c_str ());

      ACE_Manual_Event me;
      Server_Task server_task (output,
                               sorb.in (),
                               me,
                               ACE_Thread_Manager::instance ());

      if (server_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                1,
                                1) == -1)
        {
          ACE_ERROR ((LM_ERROR, "Error activating server task\n"));
        }

      // Wait for the server thread to do some processing
      me.wait ();

      ACE_Argv_Type_Converter catc (argc, argv);
      CORBA::ORB_var corb =
        CORBA::ORB_init (catc.get_argc (),
                         catc.get_TCHAR_argv (),
                         client_orb.c_str ());

      Client_Task client_task (input,
                               corb.in (),
                               syncMode,
                               ACE_Thread_Manager::instance ());

      if (client_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                1,
                                1) == -1)
        {
          ACE_ERROR ((LM_ERROR, "Error activating client task\n"));
        }

      ACE_Thread_Manager::instance ()->wait ();
    }
  catch (const CORBA::Exception&)
    {
      // Ignore exceptions..
    }
  return 0;
}
