////////////////////////////
/*
    BOJ5585 °Å½º¸§µ· 
                          */
////////////////////////////


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int cur=1000-n;
	while(1) {
		if(cur==0)
			break;
		if(cur>=500) {
 			sum+= cur/500;
			cur%=500;
			continue;
		}
		if(cur>=100) {
 			sum+= cur/100;
			cur%=100;
			continue;
		}
		if(cur>=50) {
 			sum+= cur/50;
			cur%=50;
			continue;
		}
		if(cur>=10) {
 			sum+= cur/10;
			cur%=10;
			continue;
		}
		if(cur>=5) {
 			sum+= cur/5;
			cur%=5;
			continue;
		}
		if(cur>=1) {
 			sum+=cur;
 			cur=0;
			continue;
		}
	}
	cout << sum;
	return 0;
}
