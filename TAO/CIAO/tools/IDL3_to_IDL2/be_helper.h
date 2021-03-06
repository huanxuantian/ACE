/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    be_helper.h
 *
 *  $Id: be_helper.h 93674 2011-03-29 12:15:00Z johnnyw $
 *
 *  Defines the abstract class for outputting the C++ mapping. This is a
 *  helper class to the singleton TAO_CodeGen class
 *
 *
 *  @author Aniruddha Gokhale Improvements by Carlos O'Ryan
 */
//=============================================================================


#ifndef TAO_BE_OUTSTRM_H
#define TAO_BE_OUTSTRM_H

#include "ace/CDR_Base.h"

#include "TAO_IDL3_TO_IDL2_BE_Export.h"

class Identifier;
class UTL_IdList;
class AST_Expression;

// a dummy structure to inform TAO_OutStream's << operator to  put a newline
// and use the current indentation for the succeeding line
struct TAO_IDL3_TO_IDL2_BE_Export TAO_NL
{
public:
  TAO_NL (void);
};

/**
 * Operates like a manipulator, increasing the indentation level.
 *
 * Increase the indentation level, if the "do_now" parameter is
 * not zero then the <indent> method is called on the stream.
 */
struct TAO_IDL3_TO_IDL2_BE_Export TAO_INDENT
{
  TAO_INDENT (int do_now = 0);

  const int do_now_;
};

/**
 * Operates like a manipulator, decreasing the indentation level.
 *
 * Decrease the indentation level, if the "do_now" parameter is
 * not zero then the <indent> method is called on the stream.
 */
struct TAO_IDL3_TO_IDL2_BE_Export TAO_UNINDENT
{
  TAO_UNINDENT (int do_now = 0);

  const int do_now_;
};

extern TAO_IDL3_TO_IDL2_BE_Export const TAO_NL be_nl;
extern TAO_IDL3_TO_IDL2_BE_Export const TAO_INDENT be_idt;
extern TAO_IDL3_TO_IDL2_BE_Export const TAO_INDENT be_idt_nl;
extern TAO_IDL3_TO_IDL2_BE_Export const TAO_UNINDENT be_uidt;
extern TAO_IDL3_TO_IDL2_BE_Export const TAO_UNINDENT be_uidt_nl;

/**
 * @class TAO_OutStream
 *
 * Defines an interface by which the backend code generator can
 * print its output to the underlying I/O handle. This is a
 * helper class that will be used by the TAO_CodeGen
 * class. However, this is an abstract class and classes that
 * understand specific front ends must derive from this class.
 */
class TAO_IDL3_TO_IDL2_BE_Export TAO_OutStream
{
public:
  /// constructor.
  TAO_OutStream (void);

  /// destructor.
  virtual ~TAO_OutStream (void);

  /// open the underlying low-level handle for output.
  int open (const char *fname);


  /// Return the underlying lowlevel file pointer.
  FILE *file (void);

  /// increment the indentation level and by default actually indent the output
  /// accordingly
  int incr_indent (unsigned short flag = 1);

  /// decrease the indentation level and by default actually indent the output
  /// accordingly
  int decr_indent (unsigned short flag = 1);

  /// reset indentation level to 0
  int reset (void);

  /// indent starting next line
  int indent (void);

  /// put a newline and indent on the next line
  int nl (void);

  /// "printf" style variable argument print
  int print (const char *format, ...);

  void gen_ifndef_string (const char *fname,
                          const char *prefix,
                          const char *suffix);

  // =overloaded operators

  /// output the char string and return a reference to ourselves
  TAO_OutStream &operator<< (const char *str);

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const ACE_CDR::UShort num);

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const ACE_CDR::Short num);

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const ACE_CDR::ULong num);

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const ACE_CDR::Long num);

#if defined (ACE_WIN64)
  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const ACE_CDR::ULongLong num);

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const ACE_CDR::LongLong num);
#endif /* ACE_WIN64 */

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const unsigned long num);

  /// output the integer and return a reference to ourselves
  TAO_OutStream &operator<< (const long num);

  // = MANIPULATORS

  TAO_OutStream &operator<< (const TAO_NL& nl);
  TAO_OutStream &operator<< (const TAO_INDENT& i);
  TAO_OutStream &operator<< (const TAO_UNINDENT& i);

  // The following will be provided by specialized classes.

  TAO_OutStream &operator<< (Identifier *id);
  TAO_OutStream &operator<< (AST_Expression *expr);

  // Provided by specialized classes.
  virtual TAO_OutStream &print (Identifier *id) = 0;

  virtual TAO_OutStream &print (AST_Expression *idl) = 0;

protected:
  /// The underlying low-level I/O handle.
  FILE *fp_;

  /// indentation level
  int indent_level_;
};

#endif // if !defined
