# Objetivo

Sua missão é construir um sistema de inventário que simule a mochila de loot inicial do jogador. Para isso, você criará uma struct chamada Item, que armazenará informações essenciais de cada objeto coletado. O sistema permitirá que o jogador cadastre, remova, liste e busque por itens dentro da mochila.

# Requisitos funcionais

Confira as principais funcionalidades do sistema a serem implementadas:
 
Criação da struct: definir uma struct chamada Item com os campos char nome[30], char tipo[20] e int quantidade.
 
Cadastro de itens: o sistema deve permitir que o jogador cadastre até 10 itens informando nome, tipo (ex: arma, munição e cura) e quantidade.
 
Remoção de itens: permitir que o jogador exclua um item da mochila, informando seu nome.
 
Listagem dos itens registrados com seus dados: o que deve ocorrer após cada operação.
 
Busca sequencial: implementar uma função de busca sequencial que localize um item na mochila com base no nome e exiba seus dados.
