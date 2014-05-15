#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef set<string> SetStr;
typedef map<string, SetStr*> MapStr2SetStr;

class DBConn {
public:
	void beginTxn() {}
	void endTxn() {}
	void execSql(string& sql) {}
};

class SimpleTxnLog {
public:
	SimpleTxnLog() {}
	~SimpleTxnLog() { purge(); }

	// Insert sql to a corresponding set, create a new string->Set<string> if the set doesn't exist
	void addTxn(const string& id, const string& sql) {
		SetStr* pSetStr = log_[id];	// get a SetStr by a string id, return NULL if there is no such key
		if (pSetStr == NULL) {
			pSetStr = new SetStr();
			log_[id] = pSetStr;
		}
		// Insert the sql
		pSetStr->insert(sql);
	}

	void apply() {
		// Iterate each set
		for (MapStr2SetStr::iterator p = log_.begin(); p != log_.end(); ++p) {
			conn_->beginTxn();

			// Iterate each set
			for (SetStr::iterator pSql = p->second->begin(); pSql != p->second->end(); ++pSql) {
				string s = *pSql;
				conn_->execSql(s);
				cout << "Executing SQL: " << s << endl;
			}

			conn_->endTxn();

			// Delete the used SetStr
			delete p->second;
		}

		// Clear all data
		log_.clear();
	}

	void purge() {
		// Ensure all data have been removed before destroying the instance
		for (MapStr2SetStr::const_iterator p = log_.begin(); p != log_.end(); ++p) {
			delete p->second;
		}
		log_.clear();
		cout << "All data have been destroyed." << endl;
	}
private:
	MapStr2SetStr log_;
	DBConn* conn_;
};