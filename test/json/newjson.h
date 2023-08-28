#pragma once
#include <string>
#include <memory>
#include <vector>
using std::string;
using std::vector;
class Json2;
class  NewJson {
public:
	NewJson(const NewJson& p);
	NewJson& operator=(const NewJson& p);

	NewJson(const string& str);
	NewJson();
	~NewJson();

	string toString();
	const string &getError();
	string asString();

	string getString(const string &name) const;
	int getInt(const string &name) const;
	string getString(const string &name, const string &name2) const;
	int getInt(const string &name, const string &name2) const;
	string getString(const string &name, const string &name2, const string &name3) const;
	int getInt(const string &name, const string &name2, const string &name3) const;
	std::shared_ptr<NewJson> getJson(const string &name) const;
	std::shared_ptr<NewJson> tryGetJson(const string& name) const;

	void put(const string &name, const char *value);
	void put(const string &name, const string &value);
	void put(const string &name, const string &name2, const string &value);
	void put(const string &name, NewJson &v);
	void put(const string &name, bool v);
	void put(const string &name, int v);
	void put(const string &name, long long v);

	void append(const string &name, NewJson &v);
	void append(const string &name, const string &value);
	void append(const string &name, int value);
	void clear(const string &name);
	int size(const string &name);
	std::shared_ptr<NewJson> element(const string &name, int i);

	void append(NewJson &v);
	void append(const string &value);
	void append(int value);
	void clear();
	int size();
	std::shared_ptr<NewJson> element(int i);

	void getKeys(vector<string> &keys);

private:
	Json2 *json;
};