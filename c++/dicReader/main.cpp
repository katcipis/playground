#include "Dictionary.hpp"

using namespace std;
using namespace dictionaryeditor;

int main(){
	string path = "Measurements.ndic";
	string pqp = "0046";
	
	Dictionary *m_dic = new Dictionary(path,dt_name_dictionary);
	m_dic->GetNumTerms();
	Term *m_term = m_dic->GetTerm(pqp);
	cout << m_term->ToString() << endl;
	cout << "Code : " << m_term->GetCode() << endl;
	cout << "meaning : " << m_term->GetMeaning() << endl;
	cout << "coding type : " << m_term->GetCodingType() << endl;
	cout << "description : " << m_term->GetDescription() << endl;
	cout << "designator : " << m_term->GetDesignator() << endl;
	cout << "version : " << m_term->GetVersion() << endl;
	return 0;
	
}
