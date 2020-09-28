//Agenda

#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

MYSQL conexao;
char inutil;

int ver() {
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[200], dat[10];
	char diames[5];
	int data, id;
	
	printf("De que dia você quer ver tarefa (formato dd/mm): ");
	scanf("%s", diames);
	sprintf(dat, "2005%c%c%c%c", diames[3], diames[4], diames[0], diames[1]);
	data=atoi(dat);
	
	sprintf(query, "SELECT * FROM registros WHERE data = '%d';", data);
	if (mysql_query(&conexao, query)) {
		erro();
	} else {
		res=mysql_store_result(&conexao);
		if (res) {
			while (row=mysql_fetch_row(res)) {
				printf("%s: %s\nID: %s\n\n", row[2], row[3], row[0]);
			}
		}
		mysql_free_result(res);
	}

	scanf("%c", &inutil);
	printf("Deseja deletar alguma? (s/N) ");
	scanf("%c", &inutil);
	if (inutil=='s'||inutil=='S') {
		printf("Qual o id dela? ");
		scanf("%d%c", &id, &inutil);
		if (id) {
			sprintf(query, "DELETE FROM registros WHERE id = '%d' LIMIT 1;", id);
			mysql_query(&conexao, query);
		}
	}
	printf("Ok. Aperte enter para continuar.");
	scanf("%c", &inutil, &inutil);
	return 0;
}

int cadastrar() {
	char query[800], dat[10], cha;
	char diames[5], materia[5], texto[500];
	int data, i=0;

	printf("Data (formato dd/mm): ");
	scanf("%s", diames);
	sprintf(dat, "2005%c%c%c%c", diames[3], diames[4], diames[0], diames[1]);
	data=atoi(dat);
	printf("Matéria: ");
	scanf("%s", materia);
	scanf("%c", &inutil);
	printf("Texto: ");
	while (scanf("%c", &cha)&&cha!=10) {
		texto[i]=cha;
		i++;
	}

	sprintf(query, "INSERT INTO registros VALUES ('', '%d', '%s', '%s');", data, materia, texto);
	if (mysql_query(&conexao, query)) {
		erro();
	}

	return 0;
}

int erro() {
	printf("** Erro %d: %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	return 0;
}

int main() {
	int nu;

	mysql_init(&conexao);
	
	if (!mysql_real_connect(&conexao, "127.0.0.1", "usuario", "senha", "agenda", 0, NULL, 0)) {
		erro();
		return 1;
	}

	printf("AGENDA 2005\n");
	printf("por Tiago Madeira\n");

	while (nu!=0) {
		if (nu==1) {
			ver();
		} else if (nu==2) {
			cadastrar();
		}
		printf("\n");
		printf("Opções:\n");
		printf("0. Sair\n");
		printf("1. Ver tarefas\n");
		printf("2. Cadastrar tarefa\n");

		printf("\n");
		printf("Escolha: ");
		scanf("%d", &nu);
	}

	return 0;
}
