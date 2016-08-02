#pragma once

typedef struct{
	char code[8];			// Ŀ�����
	char force;				// Ŀ�겻����ʱ���Ƿ�ǿ������
}FUZZY_TO;

typedef struct{
	void *next;
	char from[8];			// Ҫģ���ı���
	FUZZY_TO to[4];			// ģ��Ŀ��
	void *begin;			// Ҫģ�������б��Ŀ�ʼ
	void *end;				// Ҫģ�������б��Ľ���
}FUZZY_ITEM;

typedef LHashTable FUZZY_TABLE;

FUZZY_TABLE *fuzzy_table_load(const char *file);
void fuzzy_table_free(FUZZY_TABLE *ft);
FUZZY_ITEM *fuzzy_table_lookup(FUZZY_TABLE *ft,const char *code);
LArray *fuzzy_key_list(FUZZY_TABLE *ft,const char *code,int len,int split);