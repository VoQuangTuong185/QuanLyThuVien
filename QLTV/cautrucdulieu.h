#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//#DANHMUCSACH
//CAU TRUC DU LIEU DANH MUC SACH( DANH SACH LIEN KET DON)
struct Sach{
	char MASACH[15];
	int trangthai;// 0: cho muon dc; 1: da co nguoi muon; 2: sach da thanh ly
	char vitri[20];
	
	Sach(){
	}
	Sach(char ms[20], int tt, char vt[30]){
		strcpy(MASACH, ms);
		trangthai = tt;
		strcpy(vitri, vt);
	}
};

struct NodeSach{
	Sach sach;
	NodeSach *next;
};
typedef NodeSach * SachPTR;

//them vao dau
void InsertFirst_NodeSach(SachPTR &First, Sach &sach){
	SachPTR newNode = new NodeSach;	
	newNode->sach = sach;
	newNode->next = First;
	First = newNode;
}

void DeleteAllNodeSach(SachPTR &First){
	SachPTR removeNode;
	while(First != NULL){
		removeNode = First;
		First = First->next;
		delete removeNode;
	}
}

//Lay NodeSach theo masach
SachPTR GetNodeSachByMASACH(SachPTR First, char* masach){
	SachPTR node;
	for(node = First; node != NULL; node = node->next)
		if(strcmp(node->sach.MASACH, masach) == 0) return node;
	return NULL;
}

SachPTR GetNodesSachByPosition(SachPTR First, int position){
	SachPTR node = First;
	for(int i=0; node != NULL && i<position; node = node->next){
		++i;
	}
	return node;
}

//them sau node x 
bool InsertAfter_NodeSach(SachPTR &node, Sach &sach){
	SachPTR newNode;
	if(node == NULL)
		return 0;
    else{
    	newNode = new NodeSach;	
		newNode ->sach = sach;
		newNode->next = node->next;
		node->next = newNode;
		return 1;
	}
}

void InsertLast_NodeSach(SachPTR &First, Sach &sach){
	if(First == NULL) InsertFirst_NodeSach(First, sach);
	else{
		SachPTR last;
		for(last = First; last->next != NULL; last = last->next);
		InsertAfter_NodeSach(last, sach);
	}
}

bool UpdateNodeSach(SachPTR &node, Sach &sach){
	if(node == NULL) return 0;
	else{
		node->sach = sach;
		return 1;
	}
}

Sach* GetSach(SachPTR First, char* masach){
	for(SachPTR node = First; node != NULL; node = node->next)
		if(strcmp(node->sach.MASACH, masach) == 0) 
			return &node->sach;
		
	return NULL;
}

//#DAUSACH
//CAU TRUC DU LIEU DAU SACH ( DANH SACH TUYEN TINH - MANG CON TRO)
int sizeListIndexDauSachSearch = 0;
int listIndexDauSachSearch[MAXLIST_DAUSACH];

struct DauSach{
	char ISBN[11];
	char tensach[31];
	int sotrang;
	char tacgia[31];
	int nxb;
	char theloai[16];
	SachPTR First = NULL;	

	//cac thuoc tinh them
	int soluotmuon; 	
	int soluong;	
	
	DauSach(){
	}
	
	DauSach(char *isbn, char* ten, int st, char *tg, int xb, char* tl){
		strcpy(ISBN, isbn);//kich thuoc chuoi duoc sao chep phai lon hon ky tu co trong chuoi sao chep, neu khong se bi tran bo nho, du van nhap xuat duoc
		strcpy(tensach, ten);
		sotrang = st;
		strcpy(tacgia, tg);
		nxb = xb;
		strcpy(theloai, tl);
		First = NULL;		
		soluong = 0; //so luong sach moi dau sach
		soluotmuon = 0;
	}
};

struct DS_DauSach{
	int n;
	DauSach *nodes[MAXLIST_DAUSACH];
	
	DS_DauSach(){
		n = 0;
	}
	~DS_DauSach(){
		printf("Free memory dau sach + danh muc sach \n");
		while(n) {
			DeleteAllNodeSach(nodes[n-1]->First);
			delete nodes[--n];
		}
	}
};

void InsertLastDauSach(DS_DauSach &DSDS, DauSach * dausach){
	// su dung khi doc file
	if(DSDS.n > MAXLIST_DAUSACH)
		printf("DSDS day \n");
	else{
		DSDS.nodes[DSDS.n++] = dausach;
	}
}

int ExistsDauSach(DS_DauSach &DSDS, char* ISBN){
	for(int i=0; i<DSDS.n; i++){
		if(strcmp(DSDS.nodes[i]->ISBN, ISBN) == 0){
			return i;
		}
	}
	return -1;
}

bool IsPrefix(const char* pre, const char* str){
	if(strlen(pre) > strlen(str)) return false;
	for(int i=0; i<strlen(pre); i++){
		if(toupper(pre[i]) != toupper(str[i])) return false;
	}
	return true;
}

// Loc danh sach cac Dau Sach co ten bat dau la: strFind, Luu vi tri cua cac Dau Sach vao 1 mang: listIndexDauSachSearch[], 
//Size cua list se duoc luu vao bien: m
void GetListNodes(DS_DauSach &DSDS, const char* strFind, int &m){
	m = 0;
	for(int i=0; i<DSDS.n; i++){
		if(IsPrefix(strFind, DSDS.nodes[i]->tensach)){
			listIndexDauSachSearch[m++] = i;
		}
	}
}

//Them DauSach vao vi tri position trong DSDS
void InsertDauSach(DS_DauSach &DSDS, DauSach * dausach, int position){
	for(int i = DSDS.n; i > position; i--)//chay tu cuoi
		DSDS.nodes[i] = DSDS.nodes[i-1]; //swap node position => position +1
		
	DSDS.nodes[position] = dausach; //them node moi vao vi tri
	DSDS.n++; 
}

//Them DauSach vao vi tri thich hop theo de tai cho
bool AddDauSach(DS_DauSach &DSDS, DauSach *dausach){
	if(DSDS.n > MAXLIST_DAUSACH)
		return 0;
	else{
		for(int i=0; i<DSDS.n; i++){
			if(strcmp(dausach->theloai, DSDS.nodes[i]->theloai) < 0){ //insert tang dan theo the loai
				InsertDauSach(DSDS, dausach, i);
				return true;
			}		
			else if(strcmp(dausach->theloai, DSDS.nodes[i]->theloai) == 0){//cung the loai thi tang dan theo ten sachs
				if(strcmp(dausach->tensach, DSDS.nodes[i]->tensach) <= 0){
					InsertDauSach(DSDS, dausach, i);
					return true;
				}
			}
		}		
		DSDS.nodes[DSDS.n++] = dausach;//neu i = DSDS.n thi them vao cuoi
		return true;
	}
}

//Cap nhat DauSach tai vi tri i, noi dung la dausach
bool UpdateDauSach(DS_DauSach &DSDS, DauSach * dausach, int i){
	if(i >= DSDS.n || i < 0) return 0;
	else {
		// Gan dia chi con tro DMS First vao dausach moi
		dausach->First = DSDS.nodes[i]->First;
		dausach->soluong = DSDS.nodes[i]->soluong;
		dausach->soluotmuon = DSDS.nodes[i]->soluotmuon;
		
		delete DSDS.nodes[i];
		for(int j=i; j<DSDS.n; j++){
			DSDS.nodes[j] = DSDS.nodes[j+1];//lui nhung node phia sau i lai 1 index, de thay the cho i da bi xoa
		}
		DSDS.n--;
		AddDauSach(DSDS, dausach);//dam bao them lai dung thu thu de bai yeu cau
		return 1;
	}
}

int DeleteDauSach(DS_DauSach &DSDS, char* ISBN){
   int i = ExistsDauSach(DSDS,ISBN);
   if (i==-1) {
   	return -1;
   }//khong tim thay dau sach can xoa
   else  
   { 
   	 delete DSDS.nodes[i];
     for (int j=i+1; j <DSDS.n; j++)
       DSDS.nodes[j-1]=DSDS.nodes[j];
       
     DSDS.n--;  
     return 1;
	}
}

//Tim DauSach theo masach, Tra ve index cua DauSach can tim
int GetIndexDauSach(DS_DauSach &DSDS, char* ISBN){	
	for(int i=0; i<DSDS.n; i++)	
		if(strcmp(DSDS.nodes[i]->ISBN, ISBN) == 0)
			return i;			
	return -1;
}

//chua tim hieu
int GetSepPosition(char *s){
	int n = strlen(s);
	for(int i=0; i<n; i++){
		if(s[i] == '-') {
			return i;	
		}
	}
	return -1;
}

//Tim DauSach theo masach, Tra ve node cua DauSach can tim
//chua su dung va chua tim hieu
DauSach* GetDauSach(DS_DauSach &DSDS, char* masach){
	SachPTR node ;
	
	int sepPos = GetSepPosition(masach);
	char isbn[sepPos+1];
	int indexSach=0;
	
	for(int i=0; i<sepPos; i++) 
		isbn[i] = masach[i];
		
	isbn[sepPos] = '\0';
	for(int i=sepPos+1; i<strlen(masach); i++){
		indexSach = indexSach*10 + (masach[i]-'0');
	}
	for(int i=0; i<DSDS.n; i++){
		if(strcmp(DSDS.nodes[i]->ISBN, isbn) == 0){
			if(indexSach < DSDS.nodes[i]->soluong) return DSDS.nodes[i];
			else break;
		}
	}
	return NULL;
}

struct LuotMuonSach{
	int indexDS;	// vi tri cua DauSach
	int cnt;		// so luot muon
};	

struct TopSach{
	int n;
	LuotMuonSach *list;
	
	TopSach(DS_DauSach &DSDS){
		n = DSDS.n;
		list = new LuotMuonSach[n];
		for(int i=0; i<n; i++){
			list[i].indexDS = i;
			list[i].cnt = DSDS.nodes[i]->soluotmuon;
		}
		sort();
	}
	~TopSach(){
		delete[] list;
	}	
	// Phan doan
	void partition(int low, int high){
		int i = low, j = high;
		LuotMuonSach tmp;
		int pivot = list[(low+high)/2].cnt;
		do{
			while(list[i].cnt > pivot) i++;
			while(list[j].cnt < pivot) j--;
			if(i <= j){
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				i++; j--;
			}
		}while(i <= j);
		
		if(low < j) partition(low, j);
		if(i < high) partition(i, high);
	}
	void sort(){
		// Sap xep theo thu tu cnt giam dan
		// Su dung QuickSort
		partition(0, n-1);
	}
};
//#DAUSACH
//CAU TRUC DU LIEU DAU SACH ( DANH SACH TUYEN TINH - MANG CON TRO)
