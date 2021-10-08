int helper(int* p, int s, int e, int **storage){
  
  if(storage[s][e] != -1)
    return storage[s][e];
  
  if(s == e || s == e - 1){
    storage[s][e] = 0;
    return 0;
  }
  
  int min = INT_MAX;
  
  
  for(int k = s+1; k < e; k++)
  {  
     
     int ans = helper(p,s,k,storage) + helper(p,k,e,storage) + (p[k] * p[s] * p[e]);
    
     if(ans < min)
     {  min = ans;
        storage[s][e] = min;
     }
  }
  return  storage[s][e];
  
}

int mcm(int* p, int n){
  
 int** storage = new int*[n+1];
  for(int i = 0; i <= n; i++)
  {
    storage[i] = new int[n+1];
    
    for(int j = 0; j <= n; j++)
      storage[i][j] = -1;
  }
 int ans = helper(p,0,n,storage);
  return ans;

}