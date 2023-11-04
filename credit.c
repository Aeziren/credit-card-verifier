#include <cs50.h>
#include <stdio.h>

int soma_digitos_luhn();
string bandeira();

int main(void) // programa principal
{
    long card = get_long("Cartão: ");
    string marca = bandeira(card);
    int luhn = soma_digitos_luhn(card);
    if (luhn == 0) // chega se a funcao retorna o valor 0
    {
        printf("%s", marca);
    }
    else
    {
        printf("INVALID\n");
    }
}

int soma_digitos_luhn(long numero)
// funcao que avalia o numero de um cartao de acordo com o algoritmo de luhn. Se retornar 0, o cartão é válido.
{
    int tot_1 = 0, tot_2 = 0, digit = 0;
    long card1 = numero;
    long card2 = card1;
    card1  /= 10;
    while (card1 > 0) // calcula alternando e multiplicando por 2
    {
        digit = card1 % 10;
        digit *= 2;
        tot_1 += digit % 10;
        digit /= 10;
        if (digit >= 1) // avalia se o valor é de 2 digitos
        {
            tot_1 += digit % 10;
        }
        card1 /= 100;
    }
    while (card2 > 0) // calcula os outros digitos restantes
    {
        digit = card2 % 10;
        tot_2 += digit % 10;
        digit /= 10;
        if (digit >= 1) // avalia se o valor é de 2 digitos
        {
            tot_2 += digit % 10;
        }
        card2 /= 100;
    }
    return (tot_1 + tot_2) % 10;
}

string bandeira(long numero)
// algoritmo que verifica a bandeira do cartão, e também conta quantos digitos tem. Se for menor que 13 e maior que 16, invalida o cartão
{
    long card = numero;
    int num_dig = 2;
    while (card >= 100)
    {
        card /= 10;
        num_dig++; // contador de digitos
    }
    if (num_dig < 13 || num_dig > 16) // verifica os digitos
    {
        return "INVALID\n";
    }
    else if (card == 34 || card == 37)
    {
        return "AMEX\n";
    }
    else if (card >= 51 && card <= 55)
    {
        return "MASTERCARD\n";
    }
    else if (card >= 40 && card <= 49)
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}