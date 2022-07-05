# Store and Product Library 

# Compilation

## Library compilation 

```console
foo@bar:~/...$ make all
```
## Compilation result folder
```console
foo@bar:~/...$ ./bin/ 
```
____________________________________
## Tests compilation
```console
foo@bar:~/$ make test
```
## Run tests
```console
foo@bar:~/$ obj/tests
```




## Binary file header with the store info members
| Member     | Bytes           | Offset |
| ---------- | --------------- | ------ | 
| storeName  | 20              |    0   |      
| ip         | 24              |   44   |
| location   | 24              |   68   |
| phoneNumber| 8               |   76   |

 


## Product Class Structure


| Member     | Bytes           | Offset |
| ---------- | --------------- | ------ | 
| id         | 4               |   0    |
| amount     | 4               |   4    |
| name       | 20              |   8    |


code by: @indexhtml821 - Indentation by Intellisense