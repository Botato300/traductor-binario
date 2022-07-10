# Traductor Binario

## Detalles
Programa hecho en c++ que traduce un texto obtenido dado por el usuario para que posteriormente este sea convertido a código binario.
De momento, sólo puede traducir un texto a código binario. En próximas actualizaciones se podrá realizar operaraciones aritméticas con binarios, traducir de binario a texto, y viceversa.

## Funcionalidades
- Traduce de **texto a binario**.
- Traduce el **código binario a texto**. (¡No implementado aún!).
- Realiza **operaciones aritméticas** con binarios (¡No implementado aún!).

## Características
- Código simple y eficiente.
- El código fuente está modularizado para mayor organización y legibilidad del código (¡No implementado aún!)
- Documentación total del código (¡En proceso!).

# Documentación
## Funciones
### convertBinary(int decimal)
Toma como argumento un entero el cual guarda el código ASCII de un caracter del texto a traducir para que posteriormente, a través de un calculo matématico, retorne un arreglo con el octeto de binarios.
```c++
std::string convertBinary(int decimal)
{
    char bin[8];

    for(int i = 7; i >= 0; i--)
    {
        bin[i] = (decimal % 2 == 0 ? '0' : '1');
        decimal /= 2;
    }
    return bin;
}
```
