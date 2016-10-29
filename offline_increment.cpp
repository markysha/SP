// 2D
void inc2(int x1, int y1, int x2, int y2, int val){
    // [x1, y1] .. (x2, y2)
    add[x1][y1] += val;
    add[x1][y2] -= val;
    add[x2][y1] -= val;
    add[x2][y2] += val;
}

void calc2(int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            add[i][j] += (i > 0 ? add[i - 1][j] : 0) + (j > 0 ? add[i][j - 1]) - (i > 0 && j > 0 ? add[i - 1][j - 1] : 0);
        }
    }
}

// 1D 
void inc(int x1, int x2, int val){
    // [x1 .. x2)
    add[x1] += val;
    add[x2] -= val;
}

void calc(int n){
    for (int i = 1; i < n; i++){
        add[i] += add[i - 1];
    }
}
