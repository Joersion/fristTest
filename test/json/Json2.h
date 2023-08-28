#pragma once
#include <json/json.h>
#include <string>
using std::string;

class Json2 {
friend class NewJson;
public:
	Json2(const Json2& p) = delete;
	Json2& operator=(const Json2& p) = delete;
	Json2(const Json::Value &v);
	Json2(const string& str);
	Json2();

	inline Json::Value* operator->() { return &json; }
	template<class Index> inline Json::Value & operator[](Index index) {
		return json[index];
	}
	inline Json::Value& operator&() { return json; }
	const string & getError();

	string toString();
	static string toString(Json::Value& json);

private:
    Json::Value json;
	string errs;
};
