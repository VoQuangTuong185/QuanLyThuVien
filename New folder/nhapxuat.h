void Sort(int A[], int q, int r) {
    int temp;
    int i = q;
    int j = r;
    int x = A[(q + r) / 2]; 
    do { 
        while (A[i] < x) i++;
        while (A[j] > x) j--; 
        if (i <= j) 
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (q < j) 
        Sort(A, q, j);
    if (i < r) 
        Sort(A, i, r);
}

void Quick_Sort(int A[], int n) {
    Sort(A, 0, n - 1); 
}

void CreateFileMaTheDocGia(){
	int a[MAX_DOC_GIA];
	a[0]=0;
	a[1]= MAX_DOC_GIA;
	int j=2;
	int k=2;
	int TheDocGiaBST[MAX_DOC_GIA];
	int count = 0;
	while(a[1]!=1)
	{
		for(int i=0;i<j-1;i++){
			a[k]=(a[i]+a[i+1])/2;
			TheDocGiaBST[count] = a[k];
			count++;
			k++;
		}
		j=k;
		Quick_Sort(a,k);
	}
	for(int i=0;i<count;i++){
		cout<<TheDocGiaBST[i]<<"\t";
	}
	
	fstream fileMaTheDocGia;
	fileMaTheDocGia.open("data_MaTheDocGia.txt", ios::out | ios::trunc);
	fileMaTheDocGia << count << endl;	
	for(int i=0; i<count; i++)
		fileMaTheDocGia << TheDocGiaBST[i]<<"\t";
	fileMaTheDocGia.close();
}

void ReadMaTheDocGia(TDGTS_PTR &tdg){
	fstream fileMaTheDocGia;
	fileMaTheDocGia.open("data_MaTheDocGia.txt", ios::in);
	if(!fileMaTheDocGia.is_open())
		cout<<"Loi doc file data_MaTheDocGia roi!!!";		
	fileMaTheDocGia >> sizeofArrayMaTheDocGia;
	fileMaTheDocGia.ignore();		
	int temp;
	for(int i=0; i<sizeofArrayMaTheDocGia; i++){
		fileMaTheDocGia >> temp;
		InsertLast_TDGTS(tdg, temp);
	}	
	fileMaTheDocGia.close();
}

void WriteMaTheDocGia(TDGTS_PTR tdg){ 
	fstream fileMaTheDocGia;
	fileMaTheDocGia.open("data_MaTheDocGia.txt", ios::out | ios::trunc);	
	if(!fileMaTheDocGia.is_open())
		cout<<"Loi doc file data_MaTheDocGia roi!!!";		
	fileMaTheDocGia << sizeofArrayMaTheDocGia << endl;	
	for(int i=0; i<sizeofArrayMaTheDocGia; i++,tdg = tdg->next)
		fileMaTheDocGia << tdg->next->MaThe<<"\t";
	fileMaTheDocGia.close();	
}

void ReadDauSachFromFile(DS_DauSach &DSDS){
	fstream fileDauSach, fileDMS;	
	fileDauSach.open("data_dsds.txt", ios::in);
	fileDMS.open("data_dms.txt", ios::in);
	if(!fileDauSach.is_open()){
		openFileSuccess = false;
		error = DAU_SACH;
		return;
	}
	else if (!fileDMS.is_open()){
		openFileSuccess = false;
		error = SACH;
		return;		
	}
	string lineDMS;
	int n;
	fileDauSach >> n; //so luong dau sach
	fileDauSach.ignore();//xoa ki tu n ra khoi bo nho dem
	//neu bo nho dem chua co ky tu nao, no se xoa ky tu dau tien ke tiep duoc nhap tu ban phim
	int m, slm;		
	for(int i=0; i<n; i++){
		DauSach *dausach = new DauSach;
	// Co 2 cach doc file khi su dung header file fstream : toan tu >> && ham getline
	//co 4 loai: doc tung ky tu(variable is char), doc tung dong (getline), doc tung tu(variable is string ), doc file CSV 
		fileDauSach.getline(dausach->ISBN,sizeof(dausach->ISBN));
		fileDauSach.getline(dausach->tensach,sizeof(dausach->tensach));
		fileDauSach >> dausach->sotrang;								fileDauSach.ignore();
		fileDauSach.getline(dausach->tacgia,sizeof(dausach->tacgia));
		fileDauSach >> dausach->nxb;									fileDauSach.ignore();
		fileDauSach.getline(dausach->theloai,sizeof(dausach->theloai));
			
		fileDMS >> dausach->soluotmuon;	fileDMS.ignore();						
		getline(fileDMS, lineDMS);		m = atoi(lineDMS.c_str());		dausach->soluong = m;		
		for(int j=0; j<m; j++){
			Sach sach;	
			fileDMS.getline(sach.MASACH,sizeof(sach.MASACH));	
			fileDMS >> sach.trangthai;		fileDMS.ignore();
			fileDMS.getline(sach.vitri,sizeof(sach.vitri));	
			InsertLast_NodeSach(dausach->First, sach);
		}
		if (!InsertLastDauSach(DSDS, dausach)){
			openFileSuccess = false;
			error = DSDS_FULL;
			return;				
		}
	}
	fileDauSach.close();
	fileDMS.close();
}

void WriteDauSachToFile(DS_DauSach &DSDS){
	fstream fileDauSach, fileDMS;
	fileDauSach.open("data_dsds.txt", ios::out | ios::trunc);	
	fileDMS.open("data_dms.txt", ios::out | ios::trunc);
	
	fileDauSach << DSDS.n << endl;
	for(int i=0; i<DSDS.n; i++){
		fileDauSach << DSDS.nodes[i]->ISBN << endl;
		fileDauSach << DSDS.nodes[i]->tensach << endl;
		fileDauSach << DSDS.nodes[i]->sotrang << endl;
		fileDauSach << DSDS.nodes[i]->tacgia << endl;
		fileDauSach << DSDS.nodes[i]->nxb << endl;
		fileDauSach << DSDS.nodes[i]->theloai << endl;		
		fileDMS << DSDS.nodes[i]->soluotmuon << endl;
		fileDMS << DSDS.nodes[i]->soluong << endl;
		
		for(SachPTR node = DSDS.nodes[i]->First; node != NULL; node = node->next){
			fileDMS << node->sach.MASACH << endl;
			fileDMS << node->sach.trangthai << endl;
			fileDMS << node->sach.vitri << endl;
		}
	}
	fileDauSach.close();
	fileDMS.close();
}

void ReadDocGiaFromFile(DocGiaPTR &root){
	fstream fileDocGia, fileMuonTra;
	fileDocGia.open("data_docgia.txt", ios::in);
	fileMuonTra.open("data_muontra.txt", ios::in);
	if(!fileDocGia.is_open()){
		openFileSuccess = false;
		error = DOC_GIA;
		return;
	}
	else if(!fileMuonTra.is_open()){
		openFileSuccess = false;
		error = MUON_TRA;
		return;
	}
	string line, lineMT;
	
	int n;
	fileDocGia >> n;
	if(n==0){
		return;
	}
	fileDocGia.ignore();
	int m;
	for(int i=0; i<n; i++){
		DocGia dg;
		fileDocGia >> dg.MATHE;						fileDocGia.ignore();
		fileDocGia.getline(dg.ho,sizeof(dg.ho));
		fileDocGia.getline(dg.ten,sizeof(dg.ten));
		fileDocGia >> dg.phai;						fileDocGia.ignore();
		fileDocGia >> dg.trangthai;					fileDocGia.ignore();
	
		fileMuonTra >> m;							fileMuonTra.ignore();	
		for(int j=0; j<m; j++){
			MuonTra mt;
			fileMuonTra.getline(mt.MASACH,sizeof(mt.MASACH));
			fileMuonTra.getline(mt.ngaymuon,sizeof(mt.ngaymuon));
			fileMuonTra.getline(mt.ngaytra,sizeof(mt.ngaytra));
			fileMuonTra >> mt.trangthai;			fileMuonTra.ignore();
			InsertLast_MuonTra(dg.mt, mt);
		}		
		InsertDocGia(root, dg);
	}
	Duyet_DG_ID(root);
	fileMuonTra.close();
	fileDocGia.close();
}

int TotalDocGia(DocGiaPTR &root){
	if(root == NULL) return 0;
	int cnt = 0;
	Queue<NodeDocGia> q;
	NodeDocGia node;
	q.push(*root);
	while(!q.empty()){
		node = q.front();	q.pop();
		cnt++;
		if(node.left != NULL) q.push(*node.left);
		if(node.right != NULL) q.push(*node.right);
	}
	return cnt;
}
 
void WriteDocGiaToFile(DocGiaPTR &root){
	if(root== NULL) return;
	 
	fstream fileDocGia, fileMuonTra;
	fileDocGia.open("data_docgia.txt", ios::out | ios::trunc);
	fileMuonTra.open("data_muontra.txt", ios::out | ios::trunc);

	int i=0;
	Queue<NodeDocGia*> q;
	NodeDocGia *node;
	NodeMuonTra *nodeMT;
	q.push(root);
	
	fileDocGia << TotalDocGia(root) << endl;
	while(!q.empty()){
		// Lay tung doc gia ra - ghi du lieu
		node = q.front();	q.pop();		
		fileDocGia << node->docgia.MATHE << endl;
		fileDocGia << node->docgia.ho << endl;
		fileDocGia << node->docgia.ten << endl;
		fileDocGia << node->docgia.phai << endl;
		fileDocGia << node->docgia.trangthai << endl;		
		// ghi danh sach cac sach da muon 
		fileMuonTra << node->docgia.mt.total << endl;
		for(nodeMT = node->docgia.mt.First; nodeMT != NULL; nodeMT = nodeMT->next){
			fileMuonTra << nodeMT->muontra.MASACH << endl;
			fileMuonTra << nodeMT->muontra.ngaymuon << endl;
			fileMuonTra << nodeMT->muontra.ngaytra << endl;
			fileMuonTra << nodeMT->muontra.trangthai << endl;
		}	
		if(node->left != NULL) q.push(node->left);
		if(node->right != NULL) q.push(node->right);
	}
	fileMuonTra.close();
	fileDocGia.close();
}

