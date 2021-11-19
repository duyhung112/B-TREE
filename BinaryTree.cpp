#include<iostream>
using namespace std;
#include<ctime>
#include<fstream>

struct TNode
{
	int Info;
	TNode *left, *right;
};
struct BTree
{
	TNode *root;
};

TNode* CreateTNode(int x);
void initBTree(BTree &t);
bool insertTNodeLeft(TNode *&T, TNode *p);
bool insertTNodeRight(TNode *&T, TNode *p);
bool insertTNode(TNode *&root, TNode *p);
void CreateBTree_FromArray(BTree &t, int a[], int na);
void showTNode(TNode *p);

void traverseNLR(TNode *root);
void traverseNRL(TNode *root);
void traverseLNR(TNode *root);
void traverseRNL(TNode *root);
void traverseLRN(TNode *root);
void traverseRLN(TNode *root);

TNode* findTNode(TNode *root, int x);
int highTree(TNode *root);

void Delete_Tree(TNode *&root);

// ============================= BAI 1 =============================
void Xu_Ly_Bai1();
void Tao_Mang(int a[], int na);
int Dem_Nut_BST_TNode(TNode *root);
void Liet_Ke_Nut_Lon_Hon_X(TNode *root, int x, int &dem);

int Dem_Nut_La_BST_TNode(TNode *root);
int Dem_Nut_1Con_BST_TNode(TNode *root);
int Dem_Nut_2Con_BST_TNode(TNode *root);
int Tinh_Tong_Nut_La_BST_TNode(TNode *root);
int Tinh_Tong_Nut_1Con_BST_TNode(TNode *root);
int Tinh_Tong_Nut_2Con_BST_TNode(TNode *root);

// ============================= BAI 4 =============================
struct SNode
{
	TNode* data;
	SNode *next;
	bool kt_xuat;
};
struct Stack
{
	SNode *top;
};
SNode* Create_SNode(TNode* data);
void initStack(Stack &s);
void Push(Stack &s, SNode *them);
SNode* Pop(Stack &s);

void LNR_KhuDQ(TNode *root);
void RNL_KhuDQ(TNode *root);
void NLR_KhuDQ(TNode *root);
void NRL_KhuDQ(TNode *root);
void LRN_KhuDQ(TNode *root);
void RLN_KhuDQ(TNode *root);

// ============================= BAI 2 =============================
void Xu_Ly_Bai2();
struct PS
{
	int tu, mau;
};
struct TNode_PS
{
	PS data;
	TNode_PS *left, *right;
};
struct BTree_PS
{
	TNode_PS *root;
};

void Nhap_PS(PS &ps);

TNode_PS* CreateTNodePS(PS ps);
void initBTreePS(BTree_PS &t);
bool insertTNodePSLeft(TNode_PS *&T, TNode_PS *p);
bool insertTNodePSRight(TNode_PS *&T, TNode_PS *p);
bool insertTNodePS(TNode_PS *&root, TNode_PS *p);
void CreateBTreePS_FromArray(BTree_PS &t, PS arr[], int soluong);
void showTNodePS(TNode_PS *p);

void traverseNLR_PS(TNode_PS *root);
void traverseNRL_PS(TNode_PS *root);
void traverseLNR_PS(TNode_PS *root);
void traverseRNL_PS(TNode_PS *root);
void traverseLRN_PS(TNode_PS *root);
void traverseRLN_PS(TNode_PS *root);

TNode_PS* findTNodePS(TNode_PS *root, PS ps);
int highTree_PS(TNode_PS *root);

void Delete_Tree_PS(TNode_PS *&root);
int Dem_Nut_Lon_Hon_1(TNode_PS *root);

int UCLN(int a, int b);
void Toi_Gian_PS(PS &ps);
void Toi_Gian_Tree_PS(TNode_PS *&root);

void Doc_File_PS(TNode_PS *&root, char filename[]);
// ============================= BAI 3 =============================
PS Tinh_Tong_Tree_PS(TNode_PS* root);
void Tim_PS_Max(TNode_PS* root, PS &max);
void Tim_PS_Min(TNode_PS* root, PS &min);
void show_PS_Tu_Lon_Hon_Mau(TNode_PS* root, int &dem);
void show_PS_Tu_Nho_Hon_Mau(TNode_PS* root, int &dem);
bool Kiem_Tra_SNT(int n);
void show_PS_TuMau_La_SNT(TNode_PS* root, int &dem);

void show_PS_Muc_k(TNode_PS* root, int muc_k, int muc_hien_tai, int &so_lan_xuat);
int Dem_PS_Muc_k(TNode_PS* root, int muc_k, int muc_hien_tai);
PS Tinh_Tong_PS_Muc_k(TNode_PS* root, int muc_k, int muc_hien_tai);


void main()
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t\t ----------------- MENU MAIN -----------------";
		cout << "\n\t\t\t1. Bai 1 va 4.";
		cout << "\n\t\t\t2. Bai 2 va 3.";
		cout << "\n\t\t\t0. Thoat.";
		cout << "\n\t\t\t\t ---------------------------------------------";
		cout << "\n\tNhap lua chon:"; cin >> luachon;


		if (luachon == 0)
		{
			break;
		}
		else if (luachon == 1)
		{
			Xu_Ly_Bai1();
		}
		else if (luachon == 2)
		{
			Xu_Ly_Bai2();
		}
		else
		{
			cout << "\nLua chon khong hop le" << endl;
			system("pause");
		}
	}

}


// ============================= BAI 2 =============================
void Xu_Ly_Bai2()
{
	int luachon;
	BTree_PS t;
	initBTreePS(t);
	Doc_File_PS(t.root, "PS.txt");
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t\t ----------------- MENU BAI2 -----------------";
		cout << "\n\t\t\t1. Them phan so tu mang vao cay.";
		cout << "\n\t\t\t2. Them phan vao cay (tu ban phim).";
		cout << "\n\t\t\t3. Tao ngau nhien phan so trong cay.";
		cout << "\n\t\t\t4. Duyet cay.";
		cout << "\n\t\t\t5. Them con trai gia tri nut y.";
		cout << "\n\t\t\t6. Them con phai gia tri nut y.";
		cout << "\n\t\t\t7. Dem so nut phan so lon hon 1.";
		cout << "\n\t\t\t8. Toi gian tat ca phan so.";
		cout << "\n\t\t\t9. Tim nut.";
		cout << "\n\t\t\t\t ----------------- MENU BAI3 -----------------";
		cout << "\n\t\t\t10. Tinh tong tat ca phan so.";
		cout << "\n\t\t\t11. Tim phan so lon nhat/ nho nhat.";
		cout << "\n\t\t\t12. Liet ke cac phan so co tu so lon hon mau so/ nho hon mau so.";
		cout << "\n\t\t\t13. Liet ke cac phan so co tu va mau la so nguyen to.";
		cout << "\n\t\t\t14. Liet ke cac phan so muc k.";
		cout << "\n\t\t\t15. Dem so luong phan so o muc k.";
		cout << "\n\t\t\t16. Tinh tong cac phan so o muc k.";
		cout << "\n\t\t\t0. Thoat.";
		cout << "\n\t\t\t\t ---------------------------------------------";
		cout << "\n\tNhap lua chon:"; cin >> luachon;


		if (luachon == 0)
		{
			Delete_Tree_PS(t.root);
			break;
		}
		else if (luachon == 1)
		{
			int n;
			do
			{
				cout << "\nNhap so luong phan so muon tao:";
				cin >> n;
				if (n <= 0)
				{
					cout << "\nVui long nhap so luong nguyen duong!" << endl;
					system("pause");
				}
			} while (n <= 0);
			PS *arr_ps = new PS[n];
			srand((unsigned)time(NULL));
			cout << "\nCac phan so trong mang:";
			for (int i = 0; i < n; i++)
			{
				arr_ps[i].tu = rand() % (99 + 99 + 1) - 99;
				do
				{
					arr_ps[i].mau = rand() % (99 + 99 + 1) - 99;
				} while (arr_ps[i].mau == 0);
				cout << "\t" << arr_ps[i].tu << "/" << arr_ps[i].mau;
			}
			CreateBTreePS_FromArray(t, arr_ps, n);
			cout << "\nThem vao cay thanh cong." << endl;
			delete[] arr_ps;
		}
		else if (luachon == 2)
		{
			PS ps;
			cout << "\n\t\t\t NHAP PHAN SO";
			Nhap_PS(ps);
			TNode_PS* p = CreateTNodePS(ps);
			bool kt = insertTNodePS(t.root, p);
			if (kt == true)
				cout << "\nThem thanh cong." << endl;
			else cout << "\nThem that bai!" << endl;
		}
		else if (luachon == 3)
		{
			PS ps;
			srand(time(NULL));
			ps.tu = rand() % (99 + 99 + 1) - 99;
			do
			{
				ps.mau = rand() % (99 + 99 + 1) - 99;
			} while (ps.mau == 0);
			TNode_PS* p = CreateTNodePS(ps);
			bool kt = insertTNodePS(t.root, p);
			if (kt == true)
				cout << "\nTao thanh cong." << endl;
			else cout << "\nTao that bai!" << endl;
		}
		else if (luachon == 4)
		{
			if (t.root != NULL)
			{
				cout << "\nPhan so duyet cay NLR:";
				traverseNLR_PS(t.root);
				cout << "\nPhan so duyet cay NRL:";
				traverseNRL_PS(t.root);
				cout << "\nPhan so duyet cay LNR:";
				traverseLNR_PS(t.root);
				cout << "\nPhan so duyet cay RNL:";
				traverseRNL_PS(t.root);
				cout << "\nPhan so duyet cay LRN:";
				traverseLRN_PS(t.root);
				cout << "\nPhan so duyet cay RLN:";
				traverseRLN_PS(t.root);
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 5)
		{
			if (t.root != NULL)
			{
				PS tim;
				cout << "\n\t\tNHAP GIA TRI PHAN SO MUON TIM KIEM\n";
				Nhap_PS(tim);
				TNode_PS* p = findTNodePS(t.root, tim);
				if (p == NULL)
					cout << "\nPhan so nhap vao khong ton tai!" << endl;
				else
				{
					cout << "\n\t\tNHAP GIA TRI PHAN SO MUON THEM VAO CON TRAI CUA " << tim.tu << "/" << tim.mau << endl;
					PS them;
					Nhap_PS(them);
					TNode_PS* them_ps = CreateTNodePS(them);
					bool kt = insertTNodePSLeft(p, them_ps);
					if (kt == false)
						cout << "\nThem that bai!" << endl;
					else cout << "\nThem thanh cong." << endl;
				}
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 6)
		{
			if (t.root != NULL)
			{
				PS tim;
				cout << "\n\t\tNHAP GIA TRI PHAN SO MUON TIM KIEM\n";
				Nhap_PS(tim);
				TNode_PS* p = findTNodePS(t.root, tim);
				if (p == NULL)
					cout << "\nPhan so nhap vao khong ton tai!" << endl;
				else
				{
					cout << "\n\t\tNHAP GIA TRI PHAN SO MUON THEM VAO CON PHAI CUA " << tim.tu << "/" << tim.mau << endl;
					PS them;
					Nhap_PS(them);
					TNode_PS* them_ps = CreateTNodePS(them);
					bool kt = insertTNodePSRight(p, them_ps);
					if (kt == false)
						cout << "\nThem that bai!" << endl;
					else cout << "\nThem thanh cong." << endl;
				}
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 7)
		{
			if (t.root != NULL)
			{
				int dem = Dem_Nut_Lon_Hon_1(t.root);
				if (dem == 0)
					cout << "\nKhong ton tai phan so lon hon 1!" << endl;
				else cout << "\nTrong cay hien tai co " << dem << " phan so lon hon 1." << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 8)
		{
			if (t.root != NULL)
			{
				Toi_Gian_Tree_PS(t.root);
				cout << "\nToi gian tat ca thanh cong." << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 9)
		{
			if (t.root != NULL)
			{
				PS tim;
				cout << "\n\t\tNHAP GIA TRI PHAN SO MUON TIM KIEM\n";
				Nhap_PS(tim);
				TNode_PS* p = findTNodePS(t.root, tim);
				if (p == NULL)
					cout << "\nPhan so " << tim.tu << "/" << tim.mau << " nhap vao khong ton tai!" << endl;
				else cout << "\nPhan so " << tim.tu << "/" << tim.mau << " co ton tai." << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 10)
		{
			if (t.root != NULL)
			{
				PS tong = Tinh_Tong_Tree_PS(t.root);
				cout << "\n\tTong gia tri cac phan so la:" << tong.tu << "/" << tong.mau << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 11)
		{
			if (t.root != NULL)
			{
				PS max = t.root->data;
				Tim_PS_Max(t.root, max);
				cout << "\n\tPhan so lon nhat trong cay la:" << max.tu << "/" << max.mau << endl;
				PS min = t.root->data;
				Tim_PS_Min(t.root, min);
				cout << "\n\tPhan so nho nhat trong cay la:" << min.tu << "/" << min.mau << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 12)
		{
			if (t.root != NULL)
			{
				int dem = 0;
				cout << "\n\tCac phan so co tu lon hon mau la:";
				show_PS_Tu_Lon_Hon_Mau(t.root, dem);
				if (dem == 0)
					cout << "\n\tTrong cay khong ton tai phan so co tu lon hon mau!" << endl;
				dem = 0;
				cout << "\n\tCac phan so co tu nho hon mau la:";
				show_PS_Tu_Nho_Hon_Mau(t.root, dem);
				if (dem == 0)
					cout << "\n\tTrong cay khong ton tai phan so co tu nho hon mau!" << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 13)
		{
			if (t.root != NULL)
			{
				int dem = 0;
				cout << "\n\tCac phan so co tu va mau la so nguyen to:";
				show_PS_TuMau_La_SNT(t.root, dem);
				if (dem == 0)
					cout << "\n\tTrong cay khong ton tai phan so co tu va mau la so nguyen to!" << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 14)
		{
			if (t.root != NULL)
			{
				int so_lan_xuat = 0, muc_hien_tai = 0, k;
				do
				{
					cout << "\n\tNhap muc k = ";
					cin >> k;
					if (k < 0)
					{
						cout << "\nVui long nhap cho chinh xac!" << endl;
						system("pause");
					}
				} while (k < 0);
				cout << "\n\tCac phan so o muc " << k << " la:";
				show_PS_Muc_k(t.root, k, muc_hien_tai, so_lan_xuat);
				if (so_lan_xuat == 0)
					cout << "\n\tTrong cay khong ton tai muc " << k << "!" << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 15)
		{
			if (t.root != NULL)
			{
				int so_lan_xuat = 0, muc_hien_tai = 0, k;
				do
				{
					cout << "\n\tNhap muc k = ";
					cin >> k;
					if (k < 0)
					{
						cout << "\nVui long nhap cho chinh xac!" << endl;
						system("pause");
					}
				} while (k < 0);
				cout << "\n\tCac phan so o muc " << k << " la:";
				show_PS_Muc_k(t.root, k, muc_hien_tai, so_lan_xuat);
				if (so_lan_xuat == 0)
					cout << "\n\tTrong cay khong ton tai muc " << k << "!" << endl;
				else cout << "\n\tTrong cay co " << so_lan_xuat << " phan so o muc " << k << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 16)
		{
			if (t.root != NULL)
			{
				int muc_hien_tai = 0, k;
				do
				{
					cout << "\n\tNhap muc k = ";
					cin >> k;
					if (k < 0)
					{
						cout << "\nVui long nhap cho chinh xac!" << endl;
						system("pause");
					}
				} while (k < 0);
				PS tong = Tinh_Tong_PS_Muc_k(t.root, k, muc_hien_tai);
				cout << "\n\tTong cac phan so o muc " << k << " trong cay la:" << tong.tu << "/" << tong.mau << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else
		{
			cout << "\nLua chon khong hop le" << endl;
			system("pause");
		}
		cout << endl;
		system("pause");
	}
}


void Nhap_PS(PS &ps)
{
	cout << "\nNhap gia tri tu:";
	cin >> ps.tu;
	do
	{
		cout << "\nNhap gia tri mau:";
		cin >> ps.mau;
		if (ps.mau == 0)
		{
			cout << "\nVui long nhap mau khac 0!" << endl;
			system("pause");
		}
	} while (ps.mau == 0);
}
TNode_PS* CreateTNodePS(PS ps)
{
	TNode_PS* p = new TNode_PS;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!" << endl;
		system("pause");
		return NULL;
	}
	p->data.tu = ps.tu;
	p->data.mau = ps.mau;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void initBTreePS(BTree_PS &t)
{
	t.root = NULL;
}
bool insertTNodePSLeft(TNode_PS *&T, TNode_PS *p)
{
	if (T == NULL || p == NULL)
		return false;
	if (T->left != NULL)
		return false;
	T->left = p;
	return true;
}
bool insertTNodePSRight(TNode_PS *&T, TNode_PS *p)
{
	if (T == NULL || p == NULL)
		return false;
	if (T->right != NULL)
		return false;
	T->right = p;
	return true;
}
bool insertTNodePS(TNode_PS *&root, TNode_PS *p)
{
	if (p == NULL)
		return false;
	if (root == NULL)
	{
		root = p;
		return true;
	}
	else
	{
		if (root->left == NULL)
			insertTNodePS(root->left, p);
		else if (root->right == NULL)
			insertTNodePS(root->right, p);
		else
		{
			int x = rand() % 2;
			if (x == 0)
				insertTNodePS(root->left, p);
			else insertTNodePS(root->right, p);
		}
	}
	return true;
}
void CreateBTreePS_FromArray(BTree_PS &t, PS arr[], int soluong)
{
	for (int i = 0; i < soluong; i++)
	{
		TNode_PS* p = CreateTNodePS(arr[i]);
		insertTNodePS(t.root, p);
	}
}
void showTNodePS(TNode_PS *p)
{
	cout << "\t" << p->data.tu << "/" << p->data.mau;
}

void traverseNLR_PS(TNode_PS *root)
{
	if (root == NULL)
		return;
	showTNodePS(root);
	traverseNLR_PS(root->left);
	traverseNLR_PS(root->right);
}
void traverseNRL_PS(TNode_PS *root)
{
	if (root == NULL)
		return;
	showTNodePS(root);
	traverseNRL_PS(root->right);
	traverseNRL_PS(root->left);
}
void traverseLNR_PS(TNode_PS *root)
{
	if (root == NULL)
		return;
	traverseLNR_PS(root->left);
	showTNodePS(root);
	traverseLNR_PS(root->right);
}
void traverseRNL_PS(TNode_PS *root)
{
	if (root == NULL)
		return;
	traverseRNL_PS(root->right);
	showTNodePS(root);
	traverseRNL_PS(root->left);
}
void traverseLRN_PS(TNode_PS *root)
{
	if (root == NULL)
		return;
	traverseLRN_PS(root->left);
	traverseLRN_PS(root->right);
	showTNodePS(root);
}
void traverseRLN_PS(TNode_PS *root)
{
	if (root == NULL)
		return;
	traverseRLN_PS(root->right);
	traverseRLN_PS(root->left);
	showTNodePS(root);
}

TNode_PS* findTNodePS(TNode_PS *root, PS ps)
{
	if (root == NULL)
		return NULL;
	if (root->data.tu == ps.tu && root->data.mau == ps.mau)
		return root;
	TNode_PS* p = findTNodePS(root->left, ps);
	if (p != NULL)
		return p;
	return findTNodePS(root->right, ps);
}
int highTree_PS(TNode_PS *root)
{
	if (root == NULL)
		return 0;
	int hl = highTree_PS(root->left);
	int hr = highTree_PS(root->right);
	if (hl > hr)
		return hl + 1;
	return hr + 1;
}

void Delete_Tree_PS(TNode_PS *&root)
{
	if (root == NULL)
		return;
	Delete_Tree_PS(root->left);
	Delete_Tree_PS(root->right);
	delete root;
	root = NULL;
}
int Dem_Nut_Lon_Hon_1(TNode_PS *root)
{
	if (root == NULL)
		return 0;
	int dem = 0;
	if (root->data.tu < 0 && root->data.mau < 0)
	{
		if (root->data.tu < root->data.mau) // -68/-7
			dem++;
	}
	else if (root->data.tu > 0 && root->data.mau > 0)
	{
		if (root->data.tu > root->data.mau)
			dem++;
	}
	dem += Dem_Nut_Lon_Hon_1(root->left);
	dem += Dem_Nut_Lon_Hon_1(root->right);
	return dem;
}
int UCLN(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	int x = abs(a), y = abs(b);
	while (x != y)
	{
		if (x > y)
			x -= y;
		else if (x < y)
			y -= x;
	}
	return x;
}
void Toi_Gian_PS(PS &ps)
{
	int uc = UCLN(ps.tu, ps.mau);
	if (uc != 0)
	{
		ps.tu /= uc;
		ps.mau /= uc;
	}
	if (ps.tu < 0 && ps.mau < 0)
	{
		ps.tu *= (-1);
		ps.mau *= (-1);
	}
}
void Toi_Gian_Tree_PS(TNode_PS *&root)
{
	if (root == NULL)
		return;
	Toi_Gian_PS(root->data);
	Toi_Gian_Tree_PS(root->left);
	Toi_Gian_Tree_PS(root->right);
}
void Doc_File_PS(TNode_PS *&root, char filename[])
{
	ifstream In;
	In.open(filename, ios_base::in);
	if (!In)
	{
		cout << "\nLoi mo file de doc!" << endl;
		return;
	}
	while (In.eof() == false)
	{
		PS tam;
		In >> tam.tu;
		In.ignore();
		In >> tam.mau;
		In.ignore();
		TNode_PS *them = CreateTNodePS(tam);
		insertTNodePS(root, them);
	}
}
// ============================= BAI 3 =============================
PS Tinh_Tong_Tree_PS(TNode_PS* root)
{
	PS tong;
	tong.tu = 0;
	tong.mau = 1;
	if (root == NULL)
		return tong;
	tong.tu = root->data.tu;
	tong.mau = root->data.mau;
	PS tong_left = Tinh_Tong_Tree_PS(root->left);
	PS tong_right = Tinh_Tong_Tree_PS(root->right);
	tong.tu = tong.tu*tong_left.mau + tong_left.tu * tong.mau;
	tong.mau *= tong_left.mau;
	tong.tu = tong.tu*tong_right.mau + tong_right.tu * tong.mau;
	tong.mau *= tong_right.mau;
	Toi_Gian_PS(tong);
	return tong;
}
void Tim_PS_Max(TNode_PS* root, PS &max)
{
	if (root == NULL)
		return;
	// kiem tra phan so truoc khi so sanh
	if ((root->data.tu > 0 && root->data.mau < 0) || (root->data.tu < 0 && root->data.mau < 0))
	{
		root->data.tu *= (-1);
		root->data.mau *= (-1);
	}
	if (root->data.tu * max.mau > max.tu * root->data.mau)
		max = root->data;
	Tim_PS_Max(root->left, max);
	Tim_PS_Max(root->right, max);
}
void Tim_PS_Min(TNode_PS* root, PS &min)
{
	if (root == NULL)
		return;
	// kiem tra phan so truoc khi so sanh
	if ((root->data.tu > 0 && root->data.mau < 0) || (root->data.tu < 0 && root->data.mau < 0))
	{
		root->data.tu *= (-1);
		root->data.mau *= (-1);
	}
	if (root->data.tu * min.mau < min.tu * root->data.mau)
		min = root->data;
	Tim_PS_Min(root->left, min);
	Tim_PS_Min(root->right, min);
}
void show_PS_Tu_Lon_Hon_Mau(TNode_PS* root, int &dem)
{
	if (root == NULL)
		return;
	if ((root->data.tu > 0 && root->data.mau < 0) || (root->data.tu < 0 && root->data.mau < 0))
	{
		root->data.tu *= (-1);
		root->data.mau *= (-1);
	}
	if (root->data.tu > root->data.mau)
	{
		showTNodePS(root);
		dem++;
	}
	show_PS_Tu_Lon_Hon_Mau(root->left, dem);
	show_PS_Tu_Lon_Hon_Mau(root->right, dem);
}
void show_PS_Tu_Nho_Hon_Mau(TNode_PS* root, int &dem)
{
	if (root == NULL)
		return;
	if ((root->data.tu > 0 && root->data.mau < 0) || (root->data.tu < 0 && root->data.mau < 0))
	{
		root->data.tu *= (-1);
		root->data.mau *= (-1);
	}
	if (root->data.tu < root->data.mau)
	{
		showTNodePS(root);
		dem++;
	}
	show_PS_Tu_Nho_Hon_Mau(root->left, dem);
	show_PS_Tu_Nho_Hon_Mau(root->right, dem);
}
bool Kiem_Tra_SNT(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i <= (int)sqrt((float)n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void show_PS_TuMau_La_SNT(TNode_PS* root, int &dem)
{
	if (root == NULL)
		return;
	if (Kiem_Tra_SNT(root->data.tu) == true && Kiem_Tra_SNT(root->data.mau) == true)
	{
		showTNodePS(root);
		dem++;
	}
	show_PS_TuMau_La_SNT(root->left, dem);
	show_PS_TuMau_La_SNT(root->right, dem);
}

void show_PS_Muc_k(TNode_PS* root, int muc_k, int muc_hien_tai, int &so_lan_xuat)
{
	if (root == NULL)
		return;
	if (muc_hien_tai == muc_k)
	{
		showTNodePS(root);
		so_lan_xuat++;
		return;
	}
	muc_hien_tai++;
	show_PS_Muc_k(root->left, muc_k, muc_hien_tai, so_lan_xuat);
	show_PS_Muc_k(root->right, muc_k, muc_hien_tai, so_lan_xuat);
}

PS Tinh_Tong_PS_Muc_k(TNode_PS* root, int muc_k, int muc_hien_tai)
{
	PS tong;
	tong.tu = 0;
	tong.mau = 1;
	if (root == NULL)
	{
		return tong;
	}
	if (muc_hien_tai == muc_k)
	{
		tong.tu = root->data.tu;
		tong.mau = root->data.mau;
		return tong;
	}
	muc_hien_tai++;
	PS tong_left = Tinh_Tong_PS_Muc_k(root->left, muc_k, muc_hien_tai);
	PS tong_right = Tinh_Tong_PS_Muc_k(root->right, muc_k, muc_hien_tai);
	tong.tu = tong.tu * tong_left.mau + tong_left.tu * tong.mau;
	tong.mau *= tong_left.mau;
	tong.tu = tong.tu * tong_right.mau + tong_right.tu * tong.mau;
	tong.mau *= tong_right.mau;
	return tong;
}

int Dem_PS_Muc_k(TNode_PS* root, int muc_k, int muc_hien_tai)
{
	if (root == NULL)
		return 0;
	if (muc_hien_tai == muc_k)
	{
		return 1;
	}
	muc_hien_tai++;
	int dem = 0;
	dem += Dem_PS_Muc_k(root->left, muc_k, muc_hien_tai);
	dem += Dem_PS_Muc_k(root->right, muc_k, muc_hien_tai);
	return dem;
}

// ============================= BAI 1 =============================
void Xu_Ly_Bai1()
{
	int luachon;
	BTree t;
	initBTree(t);
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t\t ----------------- MENU BAI1 -----------------";
		cout << "\n\t\t\t1. Them gia tri tu mang vao cay.";
		cout << "\n\t\t\t2. Them gia tri vao cay (tu ban phim).";
		cout << "\n\t\t\t3. Tao ngau nhien gia tri trong cay.";
		cout << "\n\t\t\t4. Duyet cay.";
		cout << "\n\t\t\t5. Them con trai gia tri nut y.";
		cout << "\n\t\t\t6. Them con phai gia tri nut y.";
		cout << "\n\t\t\t7. Dem so nut trong cay.";
		cout << "\n\t\t\t8. Tim nut.";
		cout << "\n\t\t\t9. Liet ke nut lon hon x.";
		cout << "\n\t\t\t10. Dem nut la, nut 1 con, nut 2 con.";
		cout << "\n\t\t\t11. Tinh tong cac nut la, nut 1 con, nut 2 con.";
		cout << "\n\t\t\t\t ----------------- MENU BAI4 -----------------";
		cout << "\n\t\t\t12. LNR RNL NLR NRL LRN RLN.";
		cout << "\n\t\t\t0. Thoat.";
		cout << "\n\t\t\t\t ---------------------------------------------";
		cout << "\n\tNhap lua chon:"; cin >> luachon;


		if (luachon == 0)
		{
			Delete_Tree(t.root);
			break;
		}
		else if (luachon == 1)
		{
			int n;
			do
			{
				cout << "\nNhap so luong phan tu mang muon tao:";
				cin >> n;
				if (n <= 0)
				{
					cout << "\nVui long nhap so luong nguyen duong!" << endl;
					system("pause");
				}
			} while (n <= 0);
			int *a = new int[n];
			Tao_Mang(a, n);
			cout << "\nCac gia tri trong mang:";
			for (int i = 0; i < n; i++)
				cout << "\t" << a[i];
			CreateBTree_FromArray(t, a, n);
			cout << "\nThem vao cay thanh cong." << endl;
			delete[] a;
		}
		else if (luachon == 2)
		{
			int x;
			cout << "\nNhap gia tri muon them vao cay:";
			cin >> x;
			TNode* p = CreateTNode(x);
			bool kt = insertTNode(t.root, p);
			if (kt == true)
				cout << "\nThem thanh cong." << endl;
			else cout << "\nThem that bai!" << endl;
		}
		else if (luachon == 3)
		{
			int x;
			srand(time(NULL));
			x = rand() % (99 + 99 + 1) - 99;
			TNode* p = CreateTNode(x);
			bool kt = insertTNode(t.root, p);
			if (kt == true)
				cout << "\nTao thanh cong." << endl;
			else cout << "\nTao that bai!" << endl;
		}
		else if (luachon == 4)
		{
			if (t.root != NULL)
			{
				cout << "\nGia tri duyet cay LNR:";
				traverseLNR(t.root);
				cout << "\nGia tri duyet cay RNL:";
				traverseRNL(t.root);
				cout << "\nGia tri duyet cay NLR:";
				traverseNLR(t.root);
				cout << "\nGia tri duyet cay NRL:";
				traverseNRL(t.root);
				cout << "\nGia tri duyet cay LRN:";
				traverseLRN(t.root);
				cout << "\nGia tri duyet cay RLN:";
				traverseRLN(t.root);
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 5)
		{
			if (t.root != NULL)
			{
				int y;
				cout << "\nNhap gia tri nut y:";
				cin >> y;
				TNode *p = findTNode(t.root, y);
				if (p == NULL)
					cout << "\nNut khong ton tai!" << endl;
				else
				{
					int x;
					cout << "\nNhap gia tri muon them:";
					cin >> x;
					TNode *them = CreateTNode(x);
					bool kt = insertTNodeLeft(p, them);
					if (kt == true)
						cout << "\nThem thanh cong." << endl;
					else cout << "\nThem that bai!" << endl;
				}
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 6)
		{
			if (t.root != NULL)
			{
				int y;
				cout << "\nNhap gia tri nut y:";
				cin >> y;
				TNode *p = findTNode(t.root, y);
				if (p == NULL)
					cout << "\nNut khong ton tai!" << endl;
				else
				{
					int x;
					cout << "\nNhap gia tri muon them:";
					cin >> x;
					TNode *them = CreateTNode(x);
					bool kt = insertTNodeRight(p, them);
					if (kt == true)
						cout << "\nThem thanh cong." << endl;
					else cout << "\nThem that bai!" << endl;
				}
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 7)
		{
			if (t.root != NULL)
			{
				int dem = Dem_Nut_BST_TNode(t.root);
				cout << "\nHien tai cay co " << dem << " nut." << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 8)
		{
			if (t.root != NULL)
			{
				int x;
				cout << "\nNhap gia tri muon tim:";
				cin >> x;
				TNode *tim = findTNode(t.root, x);
				if (tim == NULL)
					cout << "\nGia tri khong ton tai trong cay!" << endl;
				else cout << "\nGia tri vua nhap co ton tai trong cay." << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 9)
		{
			if (t.root != NULL)
			{
				int x;
				cout << "\nNhap gia tri x:";
				cin >> x;
				int dem = 0;
				cout << "\nCac nut lon hon " << x << ":";
				Liet_Ke_Nut_Lon_Hon_X(t.root, x, dem);
				if (dem == 0)
					cout << "\nKhong ton tai nut lon hon " << x << "!\n";
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 10)
		{
			if (t.root != NULL)
			{
				int dem;
				dem = Dem_Nut_La_BST_TNode(t.root);
				cout << "\nCay hien tai co " << dem << " nut la.";
				dem = Dem_Nut_1Con_BST_TNode(t.root);
				cout << "\nCay hien tai co " << dem << " nut 1 con.";
				dem = Dem_Nut_2Con_BST_TNode(t.root);
				cout << "\nCay hien tai co " << dem << " nut 2 con." << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 11)
		{
			if (t.root != NULL)
			{
				int tong;
				tong = Tinh_Tong_Nut_La_BST_TNode(t.root);
				cout << "\nTong cac nut la:" << tong;
				tong = Tinh_Tong_Nut_1Con_BST_TNode(t.root);
				cout << "\nTong cac nut 1 con:" << tong;
				tong = Tinh_Tong_Nut_2Con_BST_TNode(t.root);
				cout << "\nTong cac nut 2 con:" << tong << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else if (luachon == 12)
		{
			if (t.root != NULL)
			{
				cout << "\n\t\t\t KHU DE QUY\n";

				cout << "LNR:";
				LNR_KhuDQ(t.root);
				cout << endl;

				cout << "RNL:";
				RNL_KhuDQ(t.root);
				cout << endl;

				cout << "NLR:";
				NLR_KhuDQ(t.root);
				cout << endl;

				cout << "NRL:";
				NRL_KhuDQ(t.root);
				cout << endl;

				cout << "LRN:";
				LRN_KhuDQ(t.root);
				cout << endl;

				cout << "RLN:";
				RLN_KhuDQ(t.root);
				cout << endl;
			}
			else cout << "\nTree isempty!" << endl;
		}
		else
		{
			cout << "\nLua chon khong hop le" << endl;
			system("pause");
		}
		cout << endl;
		system("pause");
	}
}
void Tao_Mang(int a[], int na)
{
	srand(time(NULL));
	for (int i = 0; i < na; i++)
		a[i] = rand() % (99 + 99 + 1) - 99;
}

int Dem_Nut_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	int dem = 1;
	dem += Dem_Nut_BST_TNode(root->left);
	dem += Dem_Nut_BST_TNode(root->right);
	return dem;
}

void Liet_Ke_Nut_Lon_Hon_X(TNode *root, int x, int &dem)
{
	if (root == NULL)
		return;
	if (root->Info > x)
	{
		dem++;
		cout << "\t" << root->Info;
	}
	Liet_Ke_Nut_Lon_Hon_X(root->left, x, dem);
	Liet_Ke_Nut_Lon_Hon_X(root->right, x, dem);
}

int Dem_Nut_La_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int dem = Dem_Nut_La_BST_TNode(root->left);
	return dem + Dem_Nut_La_BST_TNode(root->right);
}
int Dem_Nut_1Con_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	int dem = 0;
	if (root->left == NULL && root->right != NULL)
		dem++;
	else if (root->left != NULL && root->right == NULL)
		dem++;
	dem += Dem_Nut_1Con_BST_TNode(root->left);
	dem += Dem_Nut_1Con_BST_TNode(root->right);
	return dem;
}
int Dem_Nut_2Con_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	int dem = 0;
	if (root->left != NULL && root->right != NULL)
		dem++;
	dem += Dem_Nut_2Con_BST_TNode(root->left);
	dem += Dem_Nut_2Con_BST_TNode(root->right);
	return dem;
}
int Tinh_Tong_Nut_La_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->Info;
	int tong = Tinh_Tong_Nut_La_BST_TNode(root->left);
	return tong + Tinh_Tong_Nut_La_BST_TNode(root->right);
}
int Tinh_Tong_Nut_1Con_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	int tong = 0;
	if (root->left == NULL && root->right != NULL)
		tong += root->Info;
	else if (root->left != NULL && root->right == NULL)
		tong += root->Info;
	tong += Tinh_Tong_Nut_1Con_BST_TNode(root->left);
	tong += Tinh_Tong_Nut_1Con_BST_TNode(root->right);
	return tong;
}
int Tinh_Tong_Nut_2Con_BST_TNode(TNode *root)
{
	if (root == NULL)
		return 0;
	int tong = 0;
	if (root->left != NULL && root->right != NULL)
		tong += root->Info;
	tong += Tinh_Tong_Nut_2Con_BST_TNode(root->left);
	tong += Tinh_Tong_Nut_2Con_BST_TNode(root->right);
	return tong;
}

TNode* CreateTNode(int x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!" << endl;
		system("pause");
		return NULL;
	}
	p->Info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void initBTree(BTree &t)
{
	t.root = NULL;
}
bool insertTNodeLeft(TNode *&T, TNode *p)
{
	if (T == NULL || p == NULL)
		return false;
	if (T->left != NULL)
		return false;
	T->left = p;
	return true;
}
bool insertTNodeRight(TNode *&T, TNode *p)
{
	if (T == NULL || p == NULL)
		return false;
	if (T->right != NULL)
		return false;
	T->right = p;
	return true;
}
bool insertTNode(TNode *&root, TNode *p)
{
	if (p == NULL)
		return false;
	if (root == NULL)
	{
		root = p;
		return true;
	}
	else
	{
		if (root->left == NULL)
			insertTNode(root->left, p);
		else if (root->right == NULL)
			insertTNode(root->right, p);
		else
		{
			int x = rand() % 2;
			if (x == 0)
				insertTNode(root->left, p);
			else insertTNode(root->right, p);
		}
	}
	return true;
}
void CreateBTree_FromArray(BTree &t, int a[], int na)
{
	for (int i = 0; i < na; i++)
	{
		TNode* p = CreateTNode(a[i]);
		insertTNode(t.root, p);
	}
}
void showTNode(TNode *p)
{
	cout << "\t" << p->Info;
}
void traverseNLR(TNode *root)
{
	if (root == NULL)
		return;
	showTNode(root);
	traverseNLR(root->left);
	traverseNLR(root->right);
}
void traverseNRL(TNode *root)
{
	if (root == NULL)
		return;
	showTNode(root);
	traverseNRL(root->right);
	traverseNRL(root->left);
}
void traverseLNR(TNode *root)
{
	if (root == NULL)
		return;
	traverseLNR(root->left);
	showTNode(root);
	traverseLNR(root->right);
}
void traverseRNL(TNode *root)
{
	if (root == NULL)
		return;
	traverseRNL(root->right);
	showTNode(root);
	traverseRNL(root->left);
}
void traverseLRN(TNode *root)
{
	if (root == NULL)
		return;
	traverseLRN(root->left);
	traverseLRN(root->right);
	showTNode(root);
}
void traverseRLN(TNode *root)
{
	if (root == NULL)
		return;
	traverseRLN(root->right);
	traverseRLN(root->left);
	showTNode(root);
}

TNode* findTNode(TNode *root, int x)
{
	if (root == NULL)
		return NULL;
	if (root->Info == x)
		return root;
	TNode* p = findTNode(root->left, x);
	if (p != NULL)
		return p;
	return findTNode(root->right, x);
}
int highTree(TNode *root)
{
	if (root == NULL)
		return 0;
	int hl = highTree(root->left);
	int hr = highTree(root->right);
	if (hl > hr)
		return hl + 1;
	return hr + 1;
}

void Delete_Tree(TNode *&root)
{
	if (root == NULL)
		return;
	Delete_Tree(root->left);
	Delete_Tree(root->right);
	delete root;
	root = NULL;
}

// ============================= BAI 4 =============================
SNode* Create_SNode(TNode* data)
{
	SNode *p = new SNode;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat!" << endl;
		return NULL;
	}
	p->next = NULL;
	p->data = data;
	p->kt_xuat = false;
	return p;
}
void initStack(Stack &s)
{
	s.top = NULL;
}
void Push(Stack &s, SNode *them)
{
	if (them == NULL)
		return;
	if (s.top == NULL)
		s.top = them;
	else
	{
		them->next = s.top;
		s.top = them;
	}
}
SNode* Pop(Stack &s)
{
	if (s.top == NULL)
		return NULL;
	SNode *p = s.top;
	s.top = s.top->next;
	p->next = NULL;
	return p;
}

void LNR_KhuDQ(TNode *root)
{
	Stack s;
	initStack(s);
	// tao ra node copy moi hoan toan de khong bi mat lien ket cua cay
	TNode *copy = new TNode;
	copy->Info = root->Info;
	copy->left = root->left;
	copy->right = root->right;
	SNode *p = Create_SNode(copy);
	Push(s, p);
	while (s.top != NULL)
	{
		if (s.top->data->left != NULL)
		{
			TNode *copy_p = new TNode;
			copy_p->Info = s.top->data->left->Info;
			copy_p->left = s.top->data->left->left;
			copy_p->right = s.top->data->left->right;
			SNode *them = Create_SNode(copy_p);
			s.top->data->left = NULL;
			Push(s, them);
		}
		else
		{
			SNode *tam = Pop(s);
			cout << "\t" << tam->data->Info;
			if (tam->data->right != NULL)
			{
				TNode *copy_p = new TNode;
				copy_p->Info = tam->data->right->Info;
				copy_p->left = tam->data->right->left;
				copy_p->right = tam->data->right->right;
				SNode *them = Create_SNode(copy_p);
				tam->data->right = NULL;
				Push(s, them);
			}
		}
	}
}

void RNL_KhuDQ(TNode *root)
{
	Stack s;
	initStack(s);
	TNode *copy = new TNode;
	copy->Info = root->Info;
	copy->left = root->left;
	copy->right = root->right;
	SNode *p = Create_SNode(copy);
	Push(s, p);
	while (s.top != NULL)
	{
		if (s.top->data->right != NULL)
		{
			TNode *copy_p = new TNode;
			copy_p->Info = s.top->data->right->Info;
			copy_p->left = s.top->data->right->left;
			copy_p->right = s.top->data->right->right;
			SNode *them = Create_SNode(copy_p);
			s.top->data->right = NULL;
			Push(s, them);
		}
		else
		{
			SNode *tam = Pop(s);
			cout << "\t" << tam->data->Info;
			if (tam->data->left != NULL)
			{
				TNode *copy_p = new TNode;
				copy_p->Info = tam->data->left->Info;
				copy_p->left = tam->data->left->left;
				copy_p->right = tam->data->left->right;
				SNode *them = Create_SNode(copy_p);
				tam->data->left = NULL;
				Push(s, them);
			}
		}
	}
}
void NLR_KhuDQ(TNode *root)
{
	Stack s;
	initStack(s);
	TNode *copy = new TNode;
	copy->Info = root->Info;
	copy->left = root->left;
	copy->right = root->right;
	SNode *p = Create_SNode(copy);
	Push(s, p);
	while (s.top != NULL)
	{
		if (s.top->kt_xuat == false)
		{
			cout << "\t" << s.top->data->Info;
			s.top->kt_xuat = true;
		}

		if (s.top->data->left != NULL)
		{
			TNode *copy_p = new TNode;
			copy_p->Info = s.top->data->left->Info;
			copy_p->left = s.top->data->left->left;
			copy_p->right = s.top->data->left->right;
			SNode *them = Create_SNode(copy_p);
			s.top->data->left = NULL;
			if (s.top->data->right == NULL)
				SNode* p = Pop(s);
			Push(s, them);
		}
		else
		{
			if (s.top->data->right != NULL)
			{
				TNode *copy_p = new TNode;
				copy_p->Info = s.top->data->right->Info;
				copy_p->left = s.top->data->right->left;
				copy_p->right = s.top->data->right->right;
				SNode *them = Create_SNode(copy_p);
				s.top->data->right = NULL;
				if (s.top->data->left == NULL)
					SNode* p = Pop(s);
				Push(s, them);
			}
			else SNode* p = Pop(s);
		}
	}
}
void NRL_KhuDQ(TNode *root)
{
	Stack s;
	initStack(s);
	TNode *copy = new TNode;
	copy->Info = root->Info;
	copy->left = root->left;
	copy->right = root->right;
	SNode *p = Create_SNode(copy);
	Push(s, p);
	while (s.top != NULL)
	{
		if (s.top->kt_xuat == false)
		{
			cout << "\t" << s.top->data->Info;
			s.top->kt_xuat = true;
		}

		if (s.top->data->right != NULL)
		{
			TNode *copy_p = new TNode;
			copy_p->Info = s.top->data->right->Info;
			copy_p->left = s.top->data->right->left;
			copy_p->right = s.top->data->right->right;
			SNode *them = Create_SNode(copy_p);
			s.top->data->right = NULL;
			if (s.top->data->left == NULL)
				SNode* p = Pop(s);
			Push(s, them);
		}
		else
		{
			if (s.top->data->left != NULL)
			{
				TNode *copy_p = new TNode;
				copy_p->Info = s.top->data->left->Info;
				copy_p->left = s.top->data->left->left;
				copy_p->right = s.top->data->left->right;
				SNode *them = Create_SNode(copy_p);
				s.top->data->left = NULL;
				if (s.top->data->right == NULL)
					SNode* p = Pop(s);
				Push(s, them);
			}
			else SNode* p = Pop(s);
		}
	}
}
void LRN_KhuDQ(TNode *root)
{
	Stack s;
	initStack(s);
	TNode *copy = new TNode;
	copy->Info = root->Info;
	copy->left = root->left;
	copy->right = root->right;
	SNode *p = Create_SNode(copy);
	Push(s, p);
	while (s.top != NULL)
	{
		if (s.top->data->left == NULL && s.top->data->right == NULL)
		{
			if (s.top->kt_xuat == false)
			{
				cout << "\t" << s.top->data->Info;
				s.top->kt_xuat = true;
			}
			SNode* p = Pop(s);
		}
		else if (s.top->data->left != NULL)
		{
			TNode *copy_p = new TNode;
			copy_p->Info = s.top->data->left->Info;
			copy_p->left = s.top->data->left->left;
			copy_p->right = s.top->data->left->right;
			SNode *them = Create_SNode(copy_p);
			s.top->data->left = NULL;
			Push(s, them);
		}
		else
		{
			if (s.top->data->right != NULL)
			{
				TNode *copy_p = new TNode;
				copy_p->Info = s.top->data->right->Info;
				copy_p->left = s.top->data->right->left;
				copy_p->right = s.top->data->right->right;
				SNode *them = Create_SNode(copy_p);
				s.top->data->right = NULL;
				Push(s, them);
			}
		}
	}
}
void RLN_KhuDQ(TNode *root)
{
	Stack s;
	initStack(s);
	TNode *copy = new TNode;
	copy->Info = root->Info;
	copy->left = root->left;
	copy->right = root->right;
	SNode *p = Create_SNode(copy);
	Push(s, p);
	while (s.top != NULL)
	{
		if (s.top->data->left == NULL && s.top->data->right == NULL)
		{
			if (s.top->kt_xuat == false)
			{
				cout << "\t" << s.top->data->Info;
				s.top->kt_xuat = true;
			}
			SNode* p = Pop(s);
		}
		else if (s.top->data->right != NULL)
		{
			TNode *copy_p = new TNode;
			copy_p->Info = s.top->data->right->Info;
			copy_p->left = s.top->data->right->left;
			copy_p->right = s.top->data->right->right;
			SNode *them = Create_SNode(copy_p);
			s.top->data->right = NULL;
			Push(s, them);
		}
		else
		{
			if (s.top->data->left != NULL)
			{
				TNode *copy_p = new TNode;
				copy_p->Info = s.top->data->left->Info;
				copy_p->left = s.top->data->left->left;
				copy_p->right = s.top->data->left->right;
				SNode *them = Create_SNode(copy_p);
				s.top->data->left = NULL;
				Push(s, them);
			}
		}
	}
}