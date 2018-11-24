#include <stdio.h>
#include <ctype.h>

int Rom(char rom)
{
    rom = toupper(rom);
    switch((int)rom)
    {
        case (int)'I':
            return 1;
            break;
        case (int)'V':
            return 5;
            break;
        case (int)'X':
            return 10;
            break;

        case (int)'L':
            return 50;
            break;

        case (int)'C':
            return 100;
            break;

        case (int)'D':
            return 500;
            break;

        case (int)'M':
            return 1000;
            break;
    }
}

int Final(char *c2, char *c1)
{
    *c1 = getc(stdin);
    ungetc(*c1, stdin);
    if (*c1 == '\n')
        return Rom(*c2);
    else
        return 0;
}
int main(void)
{
    char c1, c2;
    int num = 0, temp = 0;
    printf("Digite o Algarismo em Romano a ser convertido: \n");
    c1 = getc(stdin);
    c2 = getc(stdin);
    if (c2 == '\n') num = Rom(c1);
    else do
    {
        if (Rom(c2) < Rom(c1))
        {
            num += Rom(c1) + temp;
            temp = 0;
            temp += Final(&c2, &c1);
        }
        else if (Rom(c2) == Rom(c1))
        {
            temp+= Rom(c1);
            temp+= Final(&c2, &c1);
        }
        else if (Rom(c2) > Rom(c1))
        {
            temp+= Rom(c1);
            num += Rom(c2) - temp;
            temp = 0;
            c2 = getc(stdin);
            if (c2 == '\n') ungetc(c2, stdin);
        }
        c1 = c2;
        c2 = getc(stdin);
    }while(c2 != '\n' && c1 != '\n');
    if (temp > 0) num+= temp;
    printf("O valor, em algarismos arabicos, e: %d \n", num);
}
