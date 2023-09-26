Este ejercicio trata de convertir (codificar) secuencia de caracteres en números.

```sh
tr "'"'\\\"\?\!' 01234
```

Convierte:
1. `'` → `0`
1. `\` → `1`
1. `"` → `2`
1. `?` → `3`
1. `!` → `4`

```sh
tr 'mrdoc' 01234
```

Convierte:
1. `m` → `0`
1. `r` → `1`
1. `d` → `2`
1. `o` → `3`
1. `c` → `4`

```sh
sed 's/^/obase=13; ibase=5; /'
```

añade `obase=13; ibase=5; ` al principio de la línea. Esto son instrucciones para la calculadora a continuación:

```sh
bc
```
Es una calculadora, que recibe unas instrucciones en texto y saca un resultado numérico. Las instrucciones en texto se parecen a esto:

```
obase=13; ibase=5; 10321201 + 14120222
```

Que `bc` sumará utilizando una base de entrada 5 (_input base_ o `ibase`) y una base de salida (_output base_ o `obase`) de 13.
Los números 5 y 13 representan el total de caracteres posibles en la formación de los "números" de entrada y salida.

```sh
tr 0123456789ABC 'gtaio luSnemf'
```

Cogemos el resultado de la suma y lo reemplazamos por letras de la base `gtaio luSnemf` para volver a tener un texto de salida.
