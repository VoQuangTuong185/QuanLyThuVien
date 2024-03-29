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
typedef NodeSach* SachPTR;

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
	for(int i=0; node != NULL && i<position; node = node->next, i++);//duyet toi node can get
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
	if(First == NULL) 
		InsertFirst_NodeSach(First, sach);
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
};

bool InsertLastDauSach(DS_DauSach &DSDS, DauSach * dausach){
	if(DSDS.n < MAXLIST_DAUSACH){
		DSDS.nodes[DSDS.n] = dausach;
		DSDS.n++;
		return true;
	}	
	return false;			
}

int ExistsDauSach(DS_DauSach &DSDS, char* ISBN){
	for(int i=0; i<DSDS.n; i++)
		if(strcmp(DSDS.nodes[i]->ISBN, ISBN) == 0)
			return i;
	return -1;
}

bool IsInclude(const char* typing , const char* tenSach){
	//convert const char* to string to use "find function"
	string Typing = typing; 
	string TenSach = tenSach;
	//position start found "Typing" inside "TenSach"	
	int index;
	//add space to "Typing" and "TenSach" to support finding use "strstr" function
	string Typing_Space = Typing + " "; //search 'HA_' inside 'HA_MAN'
	string Space_Typing_Space = " " + Typing + " "; //search '_HA_' inside 'lINH VU THIEN HA_'
	string TenSach_Space = TenSach + " "; 
	//converting string to c-string and Using strstr()
	//strstr : A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2
	//a null pointer if the sequence is not present in str1
	//str1: 'This is a simple string'
	//str2: 'simple'
	//=> 'simple string'
	//cout<<TenSach.find(Typing)<<endl;
	if((index = TenSach.find(Typing)) != string::npos)
		if(index==0 && strstr(TenSach.c_str(),Typing_Space.c_str()) || index!=0 && strstr(TenSach_Space.c_str(),Space_Typing_Space.c_str()))		
			return true;		
	return false;
}

//Loc danh sach cac Dau Sach co chua string "strFind", Luu vi tri cua cac Dau Sach vao 1 mang: listIndexDauSachSearch[], 
void GetListNodes(DS_DauSach &DSDS, const char* strFind, int &size_array){
	size_array = 0;
	for(int i=0; i < DSDS.n; i++)
		if(IsInclude(strFind, DSDS.nodes[i]->tensach))
			listIndexDauSachSearch[size_array++] = i;
}

//Them DauSach vao vi tri position trong DSDS
void InsertDauSach(DS_DauSach &DSDS, DauSach* dausach, int position){
	for(int i = DSDS.n; i > position; i--)
		DSDS.nodes[i] = DSDS.nodes[i-1]; //swap node position => position +1	
	DSDS.nodes[position] = dausach; //them node moi vao vi tri
	DSDS.n++; 
}

//Them DauSach vao vi tri thich hop theo de tai cho
bool Insert_DauSach_Order(DS_DauSach &DSDS, DauSach *dausach){
	if(DSDS.n +1 > MAXLIST_DAUSACH)//node moi them nam ngoai size_array bo nho da cap
		return false;	
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
bool UpdateDauSach(DS_DauSach &DSDS, DauSach* dausach, int i){
	if(i >= DSDS.n || i < 0) return 0;
	else {
		// Gan dia chi con tro DMS First vao dausach moi
		dausach->First = DSDS.nodes[i]->First;
		dausach->soluong = DSDS.nodes[i]->soluong;
		dausach->soluotmuon = DSDS.nodes[i]->soluotmuon;
		
		delete DSDS.nodes[i];
		for(int j=i; j<DSDS.n; j++)
			DSDS.nodes[j] = DSDS.nodes[j+1];//lui nhung node phia sau i lai 1 index, de thay the cho i da bi xoa
		DSDS.n--;
		Insert_DauSach_Order(DSDS, dausach);//dam bao them lai dung thu thu de bai yeu cau
		return 1;
	}
}

int DeleteDauSach(DS_DauSach &DSDS, char* ISBN){
   int i = ExistsDauSach(DSDS,ISBN);
   if (i==-1) 
   		return -1;
   else { 
   		delete DSDS.nodes[i];//xoa vung nho da cap phat cho phan tu thu i
    	for (int j=i+1; j <DSDS.n; j++)
    		DSDS.nodes[j-1]=DSDS.nodes[j];
    	DSDS.n--;  
    	return 1;
	}
}

//Tim DauSach theo masach, Tra ve node cua DauSach can tim
DauSach* GetDauSach(DS_DauSach &DSDS, char* masach){
	SachPTR node;
	int viTriNgat;	
	int n = strlen(masach);
	for(int i=0; i<n; i++)
		if(masach[i] == '-')
			viTriNgat = i;
			
	char isbn[viTriNgat+1];
	int STT_SACH=0;	
	
	for(int i=0; i<viTriNgat; i++) 
		isbn[i] = masach[i];		
	isbn[viTriNgat] = '\0';
	
	for(int i=viTriNgat+1; i<strlen(masach); i++)
		STT_SACH = STT_SACH*10 + (masach[i]-48); //48 = '0'
				
	for(int i=0; i<DSDS.n; i++)
		if(strcmp(DSDS.nodes[i]->ISBN, isbn) == 0)
			if(STT_SACH < DSDS.nodes[i]->soluong)//neu nhap TDK-11. ma soluong sach cua dau sach : 11 => loi
				return DSDS.nodes[i];		
	return NULL;
}

struct LuotMuonSach{
	int indexDS;	// vi tri cua DauSach
	int count;		// so luot muon
};	

struct TopSach{
	int n;
	LuotMuonSach *list;	
	TopSach(DS_DauSach &DSDS){
		n = DSDS.n;
		list = new LuotMuonSach[n];
		for(int i=0; i<n; i++){
			list[i].indexDS = i;
			list[i].count = DSDS.nodes[i]->soluotmuon;
		}
		// Sap xep theo thu tu count giam dan
		// Su dung QuickSort
		partition(0, n-1);
	}
	~TopSach(){
		delete[] list;
	}	
	// Phan doan
	void partition(int low, int high){
		int i = low, j = high;
		LuotMuonSach tmp;
		int pivot = list[(low+high)/2].count;
		do{
			while(list[i].count > pivot) i++;
			while(list[j].count < pivot) j--;
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
};

//#MUONTRA
//CAU TRUC DU LIEU MUON TRA (DANH SACH LIEN KET DON)
struct MuonTra{
	char MASACH[15];
	char ngaymuon[11];
	char ngaytra[11];
	int trangthai; // 0: Dang muon, 1: Da tra, 2: Lam mat
	MuonTra(){
	}
	MuonTra(char* ms, char* muon, char* tra, int tt){
		strcpy(MASACH, ms);
		strcpy(ngaymuon, muon);
		strcpy(ngaytra, tra);
		trangthai = tt;
	}
};

struct NodeMuonTra{
	MuonTra muontra; 
	NodeMuonTra *next;
};
typedef NodeMuonTra *PTRMT;

struct DS_MuonTra{
	PTRMT First = NULL;	
	//thuoc tinh them
	int total;		// tong so luong sach da muon
	int chuaTra;	// so luong sach dang muon + lam mat
	
	DS_MuonTra(){
		First = NULL;
		total = 0;
		chuaTra = 0;
	}
	~DS_MuonTra(){
	}
};

PTRMT CreateNewNode_MuonTra(MuonTra &mt){
	PTRMT newNode = new NodeMuonTra;	
	newNode->muontra = mt;
	newNode->next = NULL;	
	return newNode; 
}
 
void InsertFirst_MuonTra(DS_MuonTra &DSMT, MuonTra &mt){
	PTRMT newNode = CreateNewNode_MuonTra(mt);
	newNode->next = DSMT.First;		
	DSMT.First = newNode;
}

void InsertLast_MuonTra(DS_MuonTra &DSMT, MuonTra &mt){
	PTRMT newNode= CreateNewNode_MuonTra(mt);
	PTRMT p= CreateNewNode_MuonTra(mt);
	if(DSMT.First == NULL)
		InsertFirst_MuonTra(DSMT, mt);
	else{
		p = DSMT.First;
		while(p->next != NULL)
			p = p->next;
		p->next = newNode;
	}
	DSMT.total++;
	if(mt.trangthai != 1) 
		DSMT.chuaTra++;
}

// Tra sach + lam mat sach
void Update_MuonTra(DS_MuonTra &DSMT, MuonTra &mt){
	for(PTRMT node = DSMT.First; node != NULL; node = node->next){
		if(strcmp(node->muontra.MASACH, mt.MASACH) == 0 && strlen(node->muontra.ngaytra) == 0){
			node->muontra = mt;
			if(mt.trangthai == 1) 
				DSMT.chuaTra--;
			return;
		}
	}	
}

void DeleteAllMuonTra(DS_MuonTra &DSMT){
	PTRMT removeNode;
	while(DSMT.First != NULL){
		removeNode = DSMT.First;
		DSMT.First = DSMT.First->next;
		delete removeNode;
	}
}

//#DOCGIA
//CAU TRUC DU LIEU DOC GIA (CAY NHI PHAN TIM KIEM)
struct DocGia{
	int MATHE;
	char ho[20];
	char ten[11];
	int phai; //0: nam, 1 : nu
	int trangthai; //0: Khoa, 1: Hoat dong	 
	// dslk don luu cac cuon sach doc gia da va dang muon
	DS_MuonTra mt;
	DocGia(){
	}
	DocGia(int mt, char h[20], char t[11], int p, int tt){
		MATHE = mt;
		strcpy(ho, h);
		strcpy(ten, t);
		phai = p;
		trangthai = tt;
	}
};

struct NodeDocGia{
	DocGia docgia;
	NodeDocGia *left = NULL;
	NodeDocGia *right = NULL;
};
typedef NodeDocGia* DocGiaPTR;

struct TreeDocgia{
	int n;
	DocGia *nodes[MAX_DOC_GIA];
	int soNgayQH[MAX_DOC_GIA];
	ModeDocGia mode;
	
	TreeDocgia(){
		//mode = MODE_MA_THE;
	}
	~TreeDocgia(){	
	}	
	// Duyet InOrder
	void LNR(DocGiaPTR &node){
		if(node == NULL) return;
		LNR(node->left);
		nodes[n++] = &node->docgia;
		LNR(node->right);
	}
	
	void GetAllDocGia(DocGiaPTR &root){
		Reset();
		LNR(root);
	}
	
	int compareDG(DocGia *a, DocGia *b){
		if(mode == MODE_MA_THE)
			return a->MATHE - b->MATHE;
		else if(mode == MODE_TEN){
			/*
			strcmp: 
				return 0 neu 2 chuoi giong nhau
				return -X , gia tri am neu ki tu khac biet dau tien trong *a nho hon ki tu tuong ung trong *b trong ASCII, 				
				return X, gia tri duong neu ki tu khac biet dau tien trong *a lon hon ki tu tuong ung trong *b trong ASCII				
				neu ki tu dau 2 chuoi bang nhau, tiep tuc so ki tu tiep theo	
			*/
			if(strcmp(a->ten, b->ten) == 0)	return strcmp(a->ho, b->ho); 
			else return strcmp(a->ten, b->ten);
		}
	}
	
	void Partition(int low, int high){
		int i = low, j = high;
		DocGia* pivot = nodes[(low+high)/2];
		int pivotQH = soNgayQH[(low+high)/2];
		DocGia* temp;
		int qhTemp;		
		do{
			if(mode == MODE_QUA_HAN){
				while(soNgayQH[i] > pivotQH) i++;
				while(soNgayQH[j] < pivotQH) j--;
			}else{
				//T�m phan tu dau ti�n c� gia tri nho hon hay bang x
				while(compareDG(nodes[j], pivot) > 0) 	j--; 
				//T�m phan tu dau ti�n c� gia tri lon hon hay bang x
				while(compareDG(nodes[i], pivot) < 0)	i++; 
			}
			
			if(j>=i){//neu vi tri cua node co gia tri lon, nam phia truoc node co gia tri nho hon
				//hoan doi vi tri cho toi khi node co gia tri LON nam sau node co gia tri NHO
				temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
				if(mode == MODE_QUA_HAN){
					qhTemp = soNgayQH[i];
					soNgayQH[i] = soNgayQH[j];
					soNgayQH[j] = qhTemp;
				}
				i++; j--;
			}
		}while(i <= j);
		
		if(low < j) Partition(low, j);   //phan thu nhat co tu 2 phan tu tro len
		if(i < high) Partition(i, high); //phan thu 3 co tu 2 phan tu tro len
	}
	
	void SapXepDocGia(ModeDocGia type){
		if (n>0){
			switch(type){
				case MODE_MA_THE:{
					mode = MODE_MA_THE;	
					Partition(0, n-1);
					break;
				}
				case MODE_TEN:{
					mode = MODE_TEN;
					Partition(0, n-1);	
					break;
				}
				case MODE_QUA_HAN:{
					mode = MODE_QUA_HAN;
					Partition(0, n-1);
				}
				default:
					break;
			}
		}
	}
	
	void GetDocGiaQuaHan(NodeDocGia* &TreeDG){
		Reset();	
		ResetQH();
		Queue<NodeDocGia*> q;
		if(TreeDG != NULL) //push node root cua tree DocGia vo queue
			q.push(TreeDG);
			
		NodeDocGia* nodeDG;
		bool QUAHAN;
		while(!q.empty()){
			nodeDG = q.front();	
			q.pop();
			soNgayQH[n];
			QUAHAN = false;
			if(nodeDG->docgia.mt.chuaTra > 0)
				for(NodeMuonTra *nodeMT = nodeDG->docgia.mt.First; nodeMT != NULL; nodeMT = nodeMT->next)
					if(strlen(nodeMT->muontra.ngaytra) == 0){// chua tra sach
						int soNgayMuon = DiffTime(GetSystemDate(), nodeMT->muontra.ngaymuon);
						if(soNgayMuon > 6*24*60*60){
							soNgayQH[n] = (soNgayMuon / (24*60*60))-6; //NGAY QUA HAN SO VOI 7 NGAY CHO PHEP
							//cout<<"snqh: "<<n<<":"<<soNgayQH[n]<<endl;
							nodeDG->docgia.trangthai = 0;						
							QUAHAN = true;
						}
					}
			if(QUAHAN) nodes[n++] = &nodeDG->docgia;  //XU LY NODE			
			if(nodeDG->left != NULL) q.push(nodeDG->left);  //push node cuoi cung ben trai cua tree DocGia vo queue
			if(nodeDG->right != NULL) q.push(nodeDG->right); //push node cuoi cung ben phai cua tree DocGia vo queue
		}
		SapXepDocGia(MODE_QUA_HAN);
	}

	void Reset(){
		n = 0;
	}

	void ResetQH(){
		for(int i=0; i<MAX_DOC_GIA; i++) soNgayQH[i] = 0;
	}
};

void InsertDocGia(DocGiaPTR &node, DocGia &dg){
	if(node == NULL){
		node = new NodeDocGia;
		node->docgia = dg;
		node->left = NULL;
		node->right = NULL;
	}else{
		if(dg.MATHE < node->docgia.MATHE)
			InsertDocGia(node->left, dg);
		else if(dg.MATHE > node->docgia.MATHE)
			InsertDocGia(node->right, dg);
	}
}

DocGiaPTR TimDocGiaTheoMa(DocGiaPTR &root, int MaDocGia){
	DocGiaPTR node = root;
	while(node != NULL && node->docgia.MATHE !=MaDocGia)
		if (MaDocGia < node->docgia.MATHE) 
			node = node->left;
		else 
			node = node->right;
	return node;
}

void RemoveDocGia_SpecialCase(DocGiaPTR &node, DocGiaPTR &removeNode){
	if(node->left != NULL) 
		RemoveDocGia_SpecialCase(node->left, removeNode);
		//den day node la nut cuc trai cua cay con ben phai co nut goc la removeNode
	else{
		removeNode->docgia = node->docgia;
		removeNode = node;
		node = node->right;
	}
}

int RemoveDocGia(DocGiaPTR &node, int maDocGia){
	if(node == NULL) 
		return 0;
	if(maDocGia < node->docgia.MATHE) 
		RemoveDocGia(node->left, maDocGia);
	else if(maDocGia > node->docgia.MATHE) 
		RemoveDocGia(node->right, maDocGia);
	else{//==
		DocGiaPTR removeNode = node;
		if(node->right == NULL)//co cay con ben trai
			node = node->left;
		else if(node->left == NULL)//co cay con ben phai
			node = node->right;
		else//co 2 cay con
			RemoveDocGia_SpecialCase(node->right, removeNode);
				
		DeleteAllMuonTra(removeNode->docgia.mt);		
		delete removeNode;
		return 1;
	}
}

void UpdateDocGia(DocGiaPTR &root, DocGia &docgia){
	DocGiaPTR nodeUpdate = TimDocGiaTheoMa(root, docgia.MATHE);
	if(nodeUpdate == NULL){
		printf("K the update doc gia \n");
	}else{
		docgia.mt = nodeUpdate->docgia.mt;
		nodeUpdate->docgia = docgia;
	}	
}

// Giai phong bo nho
void DeleteMemoryDocGia(DocGiaPTR &node){
	if(node != NULL){
		DeleteMemoryDocGia(node->left);
		DeleteMemoryDocGia(node->right);		
		DeleteAllMuonTra(node->docgia.mt);		
		delete node;
	}
}

//=======================================================================================================================================//
//dslk vong de luu tru 10.000 (thuc te 8191) ma the doc gia tam thoi thoa CAY TIM KIEM NHI PHAN CAN BANG
struct TheDocGiaBSTC{  
   int MaThe;
   TheDocGiaBSTC *next;
};
typedef TheDocGiaBSTC* TDGTS_PTR;

TDGTS_PTR CreateNewNode(int MaThe) {
    TDGTS_PTR newNode = new TheDocGiaBSTC;
    newNode->MaThe = MaThe;
    return newNode;
}

void InsertLast_TDGTS(TDGTS_PTR &Last, int MaThe){
   TDGTS_PTR newNode  = CreateNewNode(MaThe);
   if (Last==NULL) newNode->next=newNode;
   else{
        newNode->next = Last->next;
	    Last->next = newNode;
   }
   Last = newNode;
}

bool DeleteFirst_TDGTS(TDGTS_PTR &Last) {
    TDGTS_PTR p;
    if (Last == NULL)
        return false;
    else{
    	// nut can xoa la nut dau
        p = Last -> next; 
        // danh sach chi co 1 nut
        if (p == Last)    
			Last = NULL;
        else    
			Last -> next = p -> next;
        delete p;
        return true;
    }
}





