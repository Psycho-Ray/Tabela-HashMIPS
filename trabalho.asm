# Uma tabela Hash implementada em Assembly MIPS para a matéria de Organização de Computadores Digitais
# Membros: Bruno Coelho, Gabriel Cruz, Gabriel Cyrillo, Alex Sander

.data
.align 0
    strInsert: .asciiz "\nDigite o valor a ser inserido: "
    strRemove: .asciiz "\nDigite o valor a ser removido: "
	strInicio: .asciiz "Tabela Hash de inteiros implementada em MIPS Assembly.\n"
	strOpcao: .asciiz  "Digite 1 para a inserção de um número, 2 para remoção, 3 para busca, 4 para a visualazição da tabela e 5 para sair do programa.\n"
	strInvalidInput: .asciiz "Opção não válida digitada, favor digitar um inteiro de 1 a 5 conforme as opções fornecidas.\n"
	strExit:.asciiz "Finalizando programa\n"

.text
.globl main

main:
	li $v0, 4	# imprime string
	la $a0, strInicio

	syscall

menu:
	li $v0, 4	# imprime string
	la $a0, strOpcao
	syscall
	li $v0, 5	# ler inteiro
	syscall 	# numero digitado em $v0
	move $s1, $v0	# guardando o numero em s1

	beq $s1, +1, insercao
	beq $s1, +2, remocao
	beq $s1, +3, busca
	beq $s1, +4 impressao
	beq $s1, +5, endProgram
	j invalidInput		# se chegar aqui, o usuario digitou algum número não valido

invalidInput:
	li $v0, 4	# imprime string
	la $a0, strInvalidInput
	syscall
	j menu		# voltamos ao menu

	
leInt:		# lê um inteiro que fica em $v0.
	li $v0, 5	# lê inteiro
	syscall
	jr $ra

# Funções Placeholders, depois coloquem as suas partes aqui.

mod:
    jr $ra

insercao:
    li $v0, 4 #imprimir string que pede valor
    la $a0, strInsert
    syscall
    li $v0, 5 #ler valor pedido
    syscall

    move $a0, $v0 #carrega como argumento0 de mod o valor lido
    jal mod

	j endProgram

remocao:
    li $v0, 4 #imprimir string que pede valor
    la $a0, strRemove
    syscall

	j endProgram

busca:
	j endProgram

impressao:
	j endProgram

endProgram:
	li $v0, 4	# imprime string
	la $a0, strExit
	syscall
	li $v0, 10	# exit
	syscall
