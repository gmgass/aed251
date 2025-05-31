/*
    Primeiro criamos a função booleana isPrefixAndSuffix:
        1. Essa função recebe duas strings como parâmetros ;
        2. Retorna verdadeiro se a primeira string for prefixo e sufixo da segunda string ;
        3. Para isso ser verdade é necessário 3 coisas:
            (a) que a string1 seja menor que a string2;
            (b) que a string2 comece com todos os caracteres da string1;
            (c) que a string2 termine com todos os caracteres da string1;
            Ou seja, retorna falso se qualquer dessas 3 condições não for cumprida.

    Depois implementamos a função countPrefixSuffixPairs:
        1. Criamos uma variável para contar quantas vezes a função isPrefixAndSuffix retorna verdadeiro.
            Ex.: int numOfPairs = 0;
        2. Criamos dois loops:
            (a) o primeiro para apontarmos para cada palavra: words[i] ;
            (b) e o segundo para apontarmos para cada palavra depois de words[i]: j = i + 1 ;
        3. Chamamos a função isPrefixAndSuffix:
            (a) comparamos words[i] com words[j] ;
            (b) se retornar verdadeiro, incrementamos a variável do passo 1 ;
        4. Por fim, retornamos a variável que contou a quantidades de retornos verdadeiros da função isPrefixAndSuffix.
            Ex.: return numOfPairs;
*/

bool isPrefixAndSuffix( const char *str1, const char *str2 ) {
    int len1 = strlen( str1 );
    int len2 = strlen( str2 );

    if ( len1 > len2 ) {
        return false;
    } else if ( strncmp( str1, str2, len1 ) != 0 || strncmp( str1, ( str2 + len2 - len1 ), len1 ) != 0) {
        return false;
    }
    return true;
}

int countPrefixSuffixPairs( char **words, int wordsSize ) {
    int nIndexPairs = 0;

    for ( int i = 0; i < wordsSize; i++ ) {
        for ( int j = i + 1; j < wordsSize; j++ ) {
            if ( isPrefixAndSuffix( words[i], words[j] ) ) {
                nIndexPairs++;
            }
        }
    }

    return nIndexPairs;
}