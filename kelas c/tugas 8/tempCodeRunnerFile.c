int min, int max){
    int range = max - min + 1;
    int count[range];
    int result[N];

    for (int i = min; i < range; i++){ //untuk bahasa C agar variable 
        count[i] = 0;                  //tidak berisi nilai sebarang
    }
    for (int i = 0; i < N; i++) {
        count[arr[i]-min]++;
    }
    for (int i = min+1; i < range;