eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# -*- perl -*-
# $Id: hang_client.pl 89547 2010-03-19 14:22:53Z mitza $

use IO::Socket;

$sock = new IO::Socket::INET (
                              PeerAddr => shift || 'localhost',
                              PeerPort => 15000,        # your server port here
                              Proto    => 'tcp',
                             );
die "Socket could not be created. Reason: $!\n" unless $sock;

# Send incomplete request
print $sock pack("H*", "47494f50010100000000006a00000001");

# Block forever...
while (1)
{
        sleep(1000);
}


