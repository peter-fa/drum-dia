


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{

    unsigned int length;
    int translate, rotate;
    char outformat; 

    char command[15];
    int status;


    void write_drum(int, int, int, int);
    void write_cymbal(int, int, int, int);
    void write_basdrum(int, int, int, int);
    void write_hihat(int, int, int, int);
    void write_length_coord(int);
    void write_rotate_coord(int);


    length = 750;
    translate = 0;
    rotate = 0;
    outformat = 0;


    if ((argc == 2) && (strcmp(argv[1], "-html") == 0)) {

        outformat = 1;

    }

    else if ((argc == 2) && (strcmp(argv[1], "-svg") == 0)) {

        outformat = 0;

    }

    else if (argc == 1) {

        outformat = 0;

    }

    else {

        fprintf(stderr, "Drum Dia: Creates drum set diagram from a text command file\n");
        fprintf(stderr, "Version 0.01 \n\n");
        fprintf(stderr, "Usage: dd < <infile.txt> > <outfile.svg> \n\n");
        fprintf(stderr, "Usage: dd -svg < <infile.txt> > <outfile.svg> \n\n");
        fprintf(stderr, "Usage: dd -html < <infile.txt> > <outfile.htm> \n\n");

        exit(1);
    }


    if (outformat == 1) {
        printf("<html><head><title></title></head><body>");
        printf("<svg width=\"2400\" height=\"1800\">");
 
    }

    else {
        printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"2400\" height=\"1800\">");

    }


    status = scanf("%10s", command);
    while (status == 1){


        /* lengths */
        if ((strlen(command) == 3) &&
            (command[0] >= '3') && (command[0] <= '9') &&
            (command[1] >= '0') && (command[1] <= '9') &&
            (command[2] >= '0') && (command[2] <= '9')) {

            length = atoi(command);            

        }


        /* rotates */
        else if ((strlen(command) == 3) &&
            (command[0] == '-') &&
            (command[1] >= '0') && (command[1] <= '9') &&
            (command[2] >= '0') && (command[2] <= '9')) {

            rotate = atoi(command);            

        }

        else if ((strlen(command) == 2) &&
            (command[0] >= '0') && (command[0] <= '9') &&
            (command[1] >= '0') && (command[1] <= '9')) {

            rotate = atoi(command);            

        }

        else if ((strlen(command) == 2) &&
            (command[0] == '-') &&
            (command[1] >= '0') && (command[1] <= '9')) {

            rotate = atoi(command);            

        }

        else if ((strlen(command) == 1) &&
            (command[0] >= '0') && (command[0] <= '9')) {

            rotate = atoi(command);            

        }


        /* translates */
        else if ((strlen(command) == 5) &&
            (command[0] == '-') &&
            (command[1] == '1') &&
            (command[2] >= '0') && (command[1] <= '9') &&
            (command[3] >= '0') && (command[2] <= '9') &&
            (command[4] == '@')) {

            translate = 0 - (((command[1] - 0x30) * 100) + ((command[2] - 0x30) * 10) + (command[3] - 0x30));            

        }

        else if ((strlen(command) == 4) &&
            (command[0] == '1') &&
            (command[1] >= '0') && (command[1] <= '9') &&
            (command[2] >= '0') && (command[2] <= '9') &&
            (command[3] == '@')) {

            translate = ((command[0] - 0x30) * 100) + ((command[1] - 0x30) * 10) + (command[2] - 0x30);            

        }

        else if ((strlen(command) == 2) &&
            (command[0] == '0') &&
            (command[1] == '@')) {

            translate = 0;            

        }


        /* drums */
        else if (strcmp(command, "dr8") == 0){

            write_drum(102, length, translate, rotate);

        }

        else if (strcmp(command, "dr10") == 0){

            write_drum(127, length, translate, rotate);

        }

        else if (strcmp(command, "dr12") == 0){

            write_drum(152, length, translate, rotate);

        }

        else if (strcmp(command, "dr13") == 0){

            write_drum(165, length, translate, rotate);

        }

        else if (strcmp(command, "dr14") == 0){

            write_drum(178, length, translate, rotate);

        }

        else if (strcmp(command, "dr16") == 0){

            write_drum(203, length, translate, rotate);

        }

        else if (strcmp(command, "dr18") == 0){

            write_drum(229, length, translate, rotate);

        }


        /* Cymbals */
        else if (strcmp(command, "cy6") == 0){

            write_cymbal(76, length, translate, rotate);

        }

        else if (strcmp(command, "cy8") == 0){

            write_cymbal(102, length, translate, rotate);

        }

        else if (strcmp(command, "cy10") == 0){

            write_cymbal(127, length, translate, rotate);

        }

        else if (strcmp(command, "cy12") == 0){

            write_cymbal(152, length, translate, rotate);

        }

        else if (strcmp(command, "cy14") == 0){

            write_cymbal(178, length, translate, rotate);

        }

        else if (strcmp(command, "cy16") == 0){

            write_cymbal(203, length, translate, rotate);

        }

        else if (strcmp(command, "cy18") == 0){

            write_cymbal(229, length, translate, rotate);

        }

        else if (strcmp(command, "cy20") == 0){

            write_cymbal(254, length, translate, rotate);

        }

        else if (strcmp(command, "cy22") == 0){

            write_cymbal(279, length, translate, rotate);

        }

        else if (strcmp(command, "cy24") == 0){

            write_cymbal(305, length, translate, rotate);

        }

        else if (strcmp(command, "cy26") == 0){

            write_cymbal(330, length, translate, rotate);

        }


        /* hi hats */
        else if (strcmp(command, "hh12") == 0){

            write_hihat(152, length, translate, rotate);

        }

        else if (strcmp(command, "hh13") == 0){

            write_hihat(165, length, translate, rotate);

        }

        else if (strcmp(command, "hh14") == 0){

            write_hihat(178, length, translate, rotate);

        }

        else if (strcmp(command, "hh15") == 0){

            write_hihat(190, length, translate, rotate);

        }


        /* bass drums */
        else if (strcmp(command, "bd18") == 0){

            write_basdrum(457, length, translate, rotate);

        }

        else if (strcmp(command, "bd20") == 0){

            write_basdrum(508, length, translate, rotate);

        }

        else if (strcmp(command, "bd22") == 0){

            write_basdrum(559, length, translate, rotate);

        }

        else if (strcmp(command, "bd24") == 0){

            write_basdrum(610, length, translate, rotate);

        }


        /* coordinate system */
        else if (strcmp(command, "c01") == 0){

            write_length_coord(1);

        }

        else if (strcmp(command, "c02") == 0){

            write_length_coord(2);

        }

        else if (strcmp(command, "c03") == 0){

            write_length_coord(3);

        }

        else if (strcmp(command, "c04") == 0){

            write_length_coord(4);

        }

        else if (strcmp(command, "c05") == 0){

            write_length_coord(5);

        }

        else if (strcmp(command, "c06") == 0){

            write_length_coord(5);

        }

        else if (strcmp(command, "c11") == 0){

            write_length_coord(1);
            write_rotate_coord(1);

        }

        else if (strcmp(command, "c12") == 0){

            write_length_coord(2);
            write_rotate_coord(1);

        }

        else if (strcmp(command, "c13") == 0){

            write_length_coord(3);
            write_rotate_coord(1);

        }

        else if (strcmp(command, "c14") == 0){

            write_length_coord(4);
            write_rotate_coord(1);

        }

        else if (strcmp(command, "c15") == 0){

            write_length_coord(5);
            write_rotate_coord(1);

        }

        else if (strcmp(command, "c16") == 0){

            write_length_coord(5);
            write_rotate_coord(1);

        }

        else if (strcmp(command, "c21") == 0){

            write_length_coord(1);
            write_rotate_coord(2);

        }

        else if (strcmp(command, "c22") == 0){

            write_length_coord(2);
            write_rotate_coord(2);

        }

        else if (strcmp(command, "c23") == 0){

            write_length_coord(3);
            write_rotate_coord(2);

        }

        else if (strcmp(command, "c24") == 0){

            write_length_coord(4);
            write_rotate_coord(2);

        }

        else if (strcmp(command, "c25") == 0){

            write_length_coord(5);
            write_rotate_coord(2);

        }

        else if (strcmp(command, "c26") == 0){

            write_length_coord(5);
            write_rotate_coord(2);

        }

        else if (strcmp(command, "c31") == 0){

            write_length_coord(1);
            write_rotate_coord(3);

        }

        else if (strcmp(command, "c32") == 0){

            write_length_coord(2);
            write_rotate_coord(3);

        }

        else if (strcmp(command, "c33") == 0){

            write_length_coord(3);
            write_rotate_coord(3);

        }

        else if (strcmp(command, "c34") == 0){

            write_length_coord(4);
            write_rotate_coord(3);

        }

        else if (strcmp(command, "c35") == 0){

            write_length_coord(5);
            write_rotate_coord(3);

        }

        else if (strcmp(command, "c36") == 0){

            write_length_coord(5);
            write_rotate_coord(3);

        }

        else if (strcmp(command, "c41") == 0){

            write_length_coord(1);
            write_rotate_coord(4);

        }

        else if (strcmp(command, "c42") == 0){

            write_length_coord(2);
            write_rotate_coord(4);

        }

        else if (strcmp(command, "c43") == 0){

            write_length_coord(3);
            write_rotate_coord(4);

        }

        else if (strcmp(command, "c44") == 0){

            write_length_coord(4);
            write_rotate_coord(4);

        }

        else if (strcmp(command, "c45") == 0){

            write_length_coord(5);
            write_rotate_coord(4);

        }

        else if (strcmp(command, "c46") == 0){

            write_length_coord(5);
            write_rotate_coord(4);

        }

        else {

            fprintf(stderr, "warning: incorrect command %s!\n", command);

        }

        status = scanf("%10s", command);

     }


    printf("</svg>");

    if (outformat == 1) {
        printf("</body></html>");

    }


    return 0;
}


void write_drum(int rad, int length, int translate, int rotate)
{

    printf("<circle cx=\"1200\" cy=\"%d\" r=\"%d\" stroke=\"black\" stroke-width=\"2\"", 1500 - length, rad);
    printf(" fill=\"grey\" transform=\"translate(%d 0) rotate(%d 1200 1500)\" />", translate, rotate); 

}


void write_cymbal(int rad, int length, int translate, int rotate)
{

    printf("<circle cx=\"1200\" cy=\"%d\" r=\"%d\" stroke=\"black\" stroke-width=\"2\"", 1500 - length, rad);
    printf(" fill=\"yellow\" transform=\"translate(%d 0) rotate(%d 1200 1500)\" />", translate, rotate); 

}


void write_basdrum(int width, int length, int translate, int rotate)
{

    printf("<g transform=\"translate(%d 0) rotate(%d 1200 1500)\">", translate, rotate);
    printf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"457\" stroke=\"black\" stroke-width=\"2\" fill=\"black\" />",
        1200 - (width / 2), 1500 - length - 228, width);
    printf("<line x1=\"1200\" y1=\"%d\" x2=\"1200\" y2=\"%d\" stroke=\"black\" stroke-width=\"10\" /></g>",
        1500 - length + 228, 1500 - length + 528);

}


void write_hihat(int rad, int length, int translate, int rotate)
{

    printf("<g transform=\"translate(%d 0) rotate(%d 1200 1500)\">", translate, rotate);
    printf("<circle cx=\"1200\" cy=\"%d\" r=\"%d\" stroke=\"black\" stroke-width=\"2\" fill=\"yellow\" />",
        1500 - length, rad);
    printf("<line x1=\"1200\" y1=\"%d\" x2=\"1200\" y2=\"%d\" stroke=\"black\" stroke-width=\"10\" /></g>",
        1500 - length + rad, 1500 - length + 300);

}


void write_length_coord(int type)
{


    switch(type){

        case 1 : printf("<circle cx=\"1200\" cy=\"1500\" r=\"1200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 break;

        case 2 : printf("<circle cx=\"1200\" cy=\"1500\" r=\"1200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"600\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 break;

        case 3 : printf("<circle cx=\"1200\" cy=\"1500\" r=\"1200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"1000\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"800\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"600\" stroke=\"black\" stroke-width=\"1\" fill=\"white\"  />");
                 break;

        case 4 : printf("<circle cx=\"1200\" cy=\"1500\" r=\"1200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"1000\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"800\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"600\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"400\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 break;

        case 5 : printf("<circle cx=\"1200\" cy=\"1500\" r=\"1200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"1100\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"1000\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"900\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"800\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"700\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"600\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"500\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 break;

        case 6 : printf("<circle cx=\"1200\" cy=\"1500\" r=\"1200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"1100\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"1000\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"900\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"800\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"700\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"600\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"500\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"400\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"300\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"200\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 printf("<circle cx=\"1200\" cy=\"1500\" r=\"100\" stroke=\"black\" stroke-width=\"1\" fill=\"white\" />");
                 break;

    }

}


void write_rotate_coord(int type)
{

    switch(type){

        case 1 : printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(0 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(90 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-90 1200 1500)\" />");
                 break;

        case 2 : printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(0 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(45 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(90 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-45 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-90 1200 1500)\" />");
                 break;

        case 3 : printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(0 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(30 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(60 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(90 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-30 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-60 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-90 1200 1500)\" />");
                 break;

        case 4 : printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(0 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(15 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(30 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(45 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(60 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(75 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(90 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-15 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-30 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-45 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-60 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-75 1200 1500)\" />");
                 printf("<line x1=\"1200\" y1=\"1500\" x2=\"1200\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" ");
                 printf("transform=\"rotate(-90 1200 1500)\" />");
                 break;

    }




}




