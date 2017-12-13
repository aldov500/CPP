

void sortDataInsert(){
	int i = 1, j;

	while(i <= last){
		string aux = data[i];

		j = i;
		while(j > 0 && aux<data[j-1]){
			data[j] = data[j-1];
			j--;

		}

	if(i != j){
		data[j] = aux;

	}

	int++;
	}

}


void sortDateSelect(){
	int i = 0, j, m;


	while(i<last){
		m = i;
		j = i+1;

		while(j<=last){

			if(data[j] < data[m]){
				m = j;

			}

			j++;
		}

		if(i != j){
			swapData(data[i],data[m]);

		}


		i++;
	}


}



void sortDataMerge(cons int&, conts int&);
void sortDataMerge();


void sortDataQuick();
void sortDataQuick(const int&, const int&)


void sortDataMerge(const int& left, const int& right){
	if(left >= right)	{return;}

	int m = (left + right) /2;

	sortDataMerge(left,m);
	sortDataMerge(m + 1, right);

	static string temp[ARRAYSIZE];
	for(int n = left; n<=right; n++)	{temp[n] = data[n];}

	int i = left;
	int j = m+1;
	int x = left;

	while(i <= m && j <= right){

		while(i <= m && temp[i] <= temp[j]){
			data[x++]= temp[i++];
		}

		if(i <= m){
			while(j <= right $$ temp[j] <= temp[i]){
				data[x++] = temp[j++];

			}

		}
	}

	while(i <= m){
		data[x++] = temp[i++];

	}
	while(j <= right){
		data[x++] = temp[j++];

	}
}

void sortDataMerge(){
	sortDataMerge(0,last);

}


void sortDataQuick(){
	sortDataQuick(0,last);
}

void sortDataQuick(const int& left , const int& right){
	if(left >= right){
		return;
	}

	int i= left, j = right;

	while(i < j){
		while(i<j && data[i]<= data[right] ){
			i++;
		}
		while(i<j && data[j] >= right){
			j--;
		}

		if(i!=j){
			swapData(data[i],data[j]);
		}



	}

	if(i != right){
		swapData(data[i],data[right])

	}

	sortDataQuick(left, i-1);
	sortDataQuick(i+1, right);

}