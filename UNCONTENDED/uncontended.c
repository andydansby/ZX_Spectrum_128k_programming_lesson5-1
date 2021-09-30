// using sccz80 1.99c

//rewriting ISR to just use the registers I need
//using advise from JorgeGV

//Using advise from Stefan
//moved Stack pointer from $BFFF to $C000 as
//Stack automatically decrements before useage
// see zpragma.inc in Uncontended

#include <arch/zx.h>
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs
//#include <intrinsic.h>//temp to place labels
//powerful troubleshooting tool
        //intrinsic_label(border_start);
        //intrinsic_label(border_end);

#include "variables.h"
#include "externs.h"
#include "uncontended.h"


void main ()
{
    //new
    SETUP_IM2();// set up for the interrupt MODE 2
    // this will point the I register to IM2 Vector

    zx_cls(PAPER_WHITE);
    printf("\x16\x01\x02");
    printf ("Main () running in uncontended\n");

    printf ("_Variable_in_contended = %d\n", Variable_in_contended);
    printf ("_Variable_in_Bank0 = %d\n", Variable_in_Bank0);

    printf ("tom = %d\n", tom);
    printf ("dick = %d\n", dick);
    printf ("harry = %d\n", harry);
    printf ("eve = %u\n", eve);
    printf ("bob = %u\n\n", bob);


    harry = add_two_numbers (tom, dick);
    printf ("Add 2 numbers %u + %u = %u\n", tom, dick, harry);

    harry = subtract2numbers (Variable_in_Bank0, eve);
    printf ("Subtract 2 numbers %u - %u = %u\n", Variable_in_Bank0, eve, harry);

    harry = multiply2numbers (Variable_in_contended, bob);
    printf ("Multiply 2 numbers %u * %u = %u\n", Variable_in_contended, bob, harry);

    harry = add_two_numbers (Variable_in_contended, Variable_in_Bank0);
    printf ("Add 2 numbers %u + %u = %u\n", Variable_in_contended, Variable_in_Bank0, harry);

    printf("\n\nPress 0-7 for Border Test\n");

    while(1)
    {
        key_test();
    }
}


// must have blank line at end
