#include<bits/stdc++.h>
#define MAX_SIZE_AREA 50
using namespace std;

/*
 * Pour rentrer les inputs il faut mettre les dimensions de l'air : longueur largeur 
 * 
 * puis un 1 pour un plein ou un 0 pour un trou*
 * ex
 * 5 5
 * 1 1 1 0 1
 * 1 1 1 0 1
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 
 * */
struct Area{
	int width;int height;
			//     X            Y
	int area[MAX_SIZE_AREA][MAX_SIZE_AREA];
	void read_input(){
		cin>>width>>height;
		for(int y=0;y<height;y++){
			for(int x=0;x<width;x++){
				cin>>area[x][y];
			}
		}
	}
	
	int compute_rec(int W,int H){
		int counter=0;
		int SEARCH_VAR = W*H;
		int rec_sum_base=0;
		for(int y=0;y<H;y++){
				for(int x=0;x<W;x++){
					rec_sum_base+=area[x][y];
				}
		}
		for(int t=0;t<(height-H+1);t++){
			
			if(t!=0){
				for(int x=0;x<W;x++){
					rec_sum_base-=area[x][t-1];
				}
				for(int x=0;x<W;x++){
					rec_sum_base+=area[x][t+H-1];
				}
			}
			int rec_sum_w = rec_sum_base;
			
			
			
			for(int x=0;x<(width-W+1);x++){
				if(rec_sum_w==SEARCH_VAR)
					counter++;
					
				//On fait glisser la fenêtre
				for(int y=t;y<t+H;y++){
					rec_sum_w-=area[x][y];
					rec_sum_w+=area[x+W][y];
				}
			}
			
			
			//check de bord
			if(rec_sum_w==SEARCH_VAR)
				counter++;
		}
		return counter;
		
	}
	int run(){
		cout<<"Donne les dimensions de ton rectangle de recherche:"<<endl;
		int W,H;cin>>W>>H;
		
		int r=compute_rec(W,H);
		
		// Pour gérer le rectangle 90degres on regarde si on a pas un carre, après on inverse les rapports
		if(W!=H){
			r+=compute_rec(H,W);
		}
		cout<<r<<endl;
		return r;
	}
};
int main(){
	Area test;
	test.read_input();
	test.run();
	return 0;
}
