using namespace std;

class matrix { 
	int **p, m, n; 
	public: 
		matrix(int row, int col) { 
			m = row; 
			n = col; 
			p = new int*[m]; 
			for (int i = 0; i < m; ++i){
				p[i] = new int[n];
				for (int j = 0; j < n; ++j)
					p[i][j] = 0;
			}
		}

		matrix& operator+ (const matrix& m1){
			return (*this += m1);
		}

		matrix& operator* (const matrix& m1){
			return (*this *= m1);
		}

		matrix& operator+= (const matrix& rhs){
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					p[i][j] += rhs.p[i][j]; 
				} 
			}      
			return *this;
		}

		matrix& operator*= (const matrix& T){
			if(n == T.m){
				for(int i = 0; i < T.m; ++i){
					for(int k = 0; k < n; ++k){
						p[i][k] *= T.p[k][i];
					}
				}
			}
			return *this;
		}

		matrix& operator= (const matrix& T){
			p = T.p;
			n = T.n;
			m = T.m;

			return *this;
		}

		void setValue(int i, int j, int value){
			p[i][j] = value;
		}

		int getValue(int i, int j){
			return p[i][j];
		}
   
};