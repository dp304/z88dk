#!perl

# $Header: /home/dom/z88dk-git/cvs/z88dk/src/z80asm/t/Attic/BUG_0002.t,v 1.1 2011-07-09 01:02:45 pauloscustodio Exp $
# Test correction of BUG_0002, see hist.c for description

use strict;
use warnings;
use Capture::Tiny::Extended 'capture';
use File::Slurp;
use File::Copy;
use Test::More;
require 't/test_utils.pl';

# create a lib name that is not removed by unlink_testfiles()
my $lib = lib_file(); $lib =~ s/\.lib$/lib.lib/i;
unlink $lib;

# create a library without Z80_STDLIB
delete $ENV{Z80_STDLIB};
write_file(asm_file(), "
	xlib one
one: 
	ld a,1
	ret
");
my($stdout, $stderr, $return) = capture {
	system z80asm()." -x".lib_file()." ".asm_file();
};
is $stdout, "", "stdout";
is $stderr, "", "stderr";
ok $return == 0, "retval";
ok -f obj_file(), obj_file()." created";
ok -f lib_file(), lib_file()." created";
is unlink(obj_file(), lib_file()), 2, "delete old obj and lib";

# create the same library with Z80_STDLIB
# cause the buffer overrun, detected in MSVC debug version
$ENV{Z80_STDLIB} = lib_file();
($stdout, $stderr, $return) = capture {
	system z80asm()." -x ".asm_file();
};
is $stdout, "", "stdout";
is $stderr, "", "stderr";
ok $return == 0, "retval";
ok -f obj_file(), obj_file()." created";
ok -f lib_file(), lib_file()." created";

# link with the library without Z80_STDLIB
ok copy(lib_file(), $lib), "create $lib";
delete $ENV{Z80_STDLIB};
t_z80asm_ok(0, "
	lib one
	jp one
", "\xC3\x03\x00\x3E\x01\xC9", "-i$lib");

# link with the library with Z80_STDLIB
# cause the buffer overrun, detected in MSVC debug version
$ENV{Z80_STDLIB} = $lib;
t_z80asm_ok(0, "
	lib one
	jp one
", "\xC3\x03\x00\x3E\x01\xC9", "-i");


unlink_testfiles();
is unlink($lib), 1, "delete $lib";
done_testing();
