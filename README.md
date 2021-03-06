# Ordenações em C - Difereça de tempo (segundos)
Programa calcula o tempo dos principais métodos de ordenações em C. Usamos o Make para compilar

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/igorlamoia/C-ordenacoes-tempo/blob/main/LICENSE)


## Objetivo :bookmark_tabs:
 Sabemos que o tempo varia de acordo com a máquina, porém a comparação nos dá uma ideia da eficiência/custo de cada método.
 
 <p align="center">
 <a href="#instalação">Instalação</a>&nbsp;&nbsp;&nbsp;
</p>

 ## Métodos
![image](https://user-images.githubusercontent.com/62469164/124341548-82703800-db93-11eb-8336-7e350a728958.png) 

![Image declaracoes](./images/metodos.png)


## Main (includes) :star:
![Image declaracoes](./images/main.png)


## Inicialização :clapper:
![Image declaracoes](./images/inicializacao.png)


## Menu :computer:
![Image declaracoes](./images/menu.png)

## Escolha de Método e Ordenação 
![image](https://user-images.githubusercontent.com/62469164/124341687-79cc3180-db94-11eb-8c51-07ca9bca3f93.png)

![Image declaracoes](./images/escolhas.png)


# Instalação
## Instruções - Windows 10

Realize o download de minGW: https://sourceforge.net/projects/mingw/

Prossiga com a instalação. Após concluída, selecione mingw32-base e mingw32-gcc-g++ para instalar.

![Image declaracoes](./images/setup-windows-1.PNG)

Logo após vá em Installation > Apply Changes

![Image declaracoes](./images/setup-windows-2.PNG)

![Image declaracoes](./images/setup-windows-3.PNG)


Para adicionar gcc como variável de ambiente, vá em Meu Computador > Propriedades.

Depois vá em Configurações avançadas do sistema > Variáveis de Ambiente.

Ache a variável Path e clique em Editar.

Clique em Novo... e adicione o diretório dos binários que foram instalados com o MinGW (geralmente em C:\MinGW\bin)

Para conferir que a variável foi adicionada, reinicie seu terminal e execute o comando gcc.

Após isso é necessário a instalação do make. Caso possua chocolatey, inicie o `PowerShell` em modo administrador e execute o comando:

```
choco install make
```

Após isso, clone o repositório. Execute, na pasta do projeto, o comando `make` para gerar o arquivo executável e `make run` para executá-lo.
