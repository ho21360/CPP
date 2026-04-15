#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// [1번 문제] 
struct WordPair {
    string eng;
    string kor;
};

const int MAXWORDS = 100;

// [2번 문제]
class MyDic {
    // 멤버 변수: 구조체 배열과 현재 단어 수
    WordPair words[MAXWORDS]; 
    int nWords = 0;           

public:
    // 모든 멤버 함수를 클래스 내부에 inline으로 구현
    
    // 단어 추가 기능
    void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    // 파일에서 단어 읽기
    void load(string filename) {
        ifstream fin(filename);
        if (fin.is_open()) {
            while (nWords < MAXWORDS && fin >> words[nWords].eng >> words[nWords].kor) {
                nWords++;
            }
            fin.close();
        }
    }

    // 파일에 단어 저장 
    void store(string filename) {
        ofstream fout(filename);
        if (fout.is_open()) {
            for (int i = 0; i < nWords; i++) {
                fout << words[i].eng << " " << words[i].kor << endl;
            }
            fout.close();
        }
    }

    // 화면 출력 기능
    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << words[i].eng << " : " << words[i].kor << endl;
        }
    }

    //  영어 단어 반환
    string getEng(int id) {
        if (id >= 0 && id < nWords) return words[id].eng;
        return "";
    }

    //  한글 뜻 반환
    string getKor(int id) {
        if (id >= 0 && id < nWords) return words[id].kor;
        return "";
    }
};

// [3번 문제] 
int main() {
    MyDic dic;

    // 자신만의 데이터 등록 (스포츠 종목)
    dic.add("Baseball", "야구");
    dic.add("Basketball", "농구");
    dic.add("Soccer", "축구");

    dic.print();
    dic.store("mysports.txt");

    return 0;
}