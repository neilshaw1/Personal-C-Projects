#include<iostream>
#include<algorithm>
using namespace std;
double findHighest(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double calcScore(double score1, double score2, double score3, double score4, double score5);
void getJudgeData(double &score, int i);

int main(){
	double score1, score2, score3, score4, score5;
	getJudgeData(score1,1);
	getJudgeData(score2,2);
	getJudgeData(score3,3);
	getJudgeData(score4,4);
	getJudgeData(score5,5);
	calcScore(score1, score2, score3, score4, score5);
}

double findLowest(double score1, double score2, double score3, double score4, double score5){
	return min(score1,min(score2,min(score3,min(score4,score5))));
}

double findHighest(double score1, double score2, double score3, double score4, double score5){
	return max(score1,max(score2,max(score3,max(score4,score5))));
}

void getJudgeData(double &score, int i){
	cout<<"Enter score #"<<i<<": ";
	cin>>score;
	while (score<0 || score>10){
		cout<<"That answer is invalid.\n";
		cout<<"Enter score #"<<i<<": ";
		cin>>score;
	}
}

double calcScore(double score1, double score2, double score3, double score4, double score5){
	double highest = findHighest(score1, score2, score3, score4, score5);
	double lowest = findLowest(score1, score2, score3, score4, score5);
	double average = ((score1+score2+score3+score4+score5-highest-lowest)/3);
	cout<<"The average is "<<average;
}
