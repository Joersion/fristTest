#include "Json2.h"
#include "newjson.h"
#include <memory>
#include <boost/lexical_cast.hpp>
using std::unique_ptr;

static const char *empty = "";
NewJson::NewJson(const NewJson& p)
{
	json = new Json2(p.json->json);
}


NewJson::NewJson(const string &str)
{
	json = new Json2(str);
}

NewJson::NewJson()
{
	json = new Json2();
}

NewJson& NewJson::operator=(const NewJson& p)
{
	if (this == &p) {
		return *this;
	}
	if (this->json != 0) {
		delete this->json;
	}
	this->json = new Json2(p.json->json);
	return *this;
}

NewJson::~NewJson()
{
	delete json;
}

const string & NewJson::getError()
{
	return json->getError();
}

string NewJson::toString()
{
	return json->toString();
}

string NewJson::asString()
{
	try {
		return (*json)->asString();
	} catch (...) {
		return "";
	}
}

string NewJson::getString(const string &name) const
{
	try {
		return (*json)->get(name, "").asString();
	} catch (...) {
		return "";
	}
}

int NewJson::getInt(const string &name) const
{
	try {
		return (*json)->get(name, 0).asInt();
	} catch (...) {
		return atoi(getString(name).c_str());
	}
}

string NewJson::getString(const string &name, const string &name2) const
{
	try {
		if ((*json)[name].isObject() == false) {
			string v = (*json)->get(name, "").asString();
			if (v == "") {
				return empty;
			}
			Json2 json2(v);
			return json2->get(name2, "").asString();
		}
		return (*json)[name].get(name2, "").asString();
	} catch (...) {
		return "";
	}
}

int NewJson::getInt(const string &name, const string &name2) const
{
	try {
		if ((*json)[name].isObject() == false) {
			string v = (*json)->get(name, "").asString();
			if (v == "") {
				return 0;
			}
			Json2 json2(v);
			return json2->get(name2, "").asInt();
		}
		return (*json)[name].get(name2, 0).asInt();
	} catch (...) {
		return atoi(getString(name, name2).c_str());
	}
}

string  NewJson::getString(const string &name, const string &name2, const string &name3) const
{
	try {
		if ((*json)[name].isObject() == false) {
			string v = (*json)->get(name, "").asString();
			if (v == "") {
				return "";
			}
			NewJson json2(v);
			return json2.getString(name2, name3);
		}
		if ((*json)[name][name2].isObject() == false) {
			string v = (*json)[name].get(name2, "").asString();
			if (v == "") {
				return empty;
			}
			Json2 json2(v);
			return json2->get(name3, "").asString();
		}
		return (*json)[name][name2].get(name3, "").asString();
	} catch (...) {
		return "";
	}
}

int NewJson::getInt(const string &name, const string &name2, const string &name3) const
{
	try {
		if ((*json)[name].isObject() == false) {
			return 0;
		}
		if ((*json)[name][name2].isObject() == false) {
			return 0;
		}
		return (*json)[name][name2].get(name3, 0).asInt();
	} catch (...) {
		return atoi(getString(name, name2, name3).c_str());
	}
}

std::shared_ptr<NewJson> NewJson::getJson(const string &name) const
{
	std::shared_ptr<NewJson> ret(new NewJson);
	try {
		if ((*json)[name].isObject() == false && (*json)[name].isArray() == false) {
			return ret;
		}
		delete ret->json;
		ret->json = new Json2((*json)[name]);
		return ret;
	} catch (...) {
		return ret;
	}
}

std::shared_ptr<NewJson> NewJson::tryGetJson(const string& name) const {
	std::shared_ptr<NewJson> ret;
	try {
		if ((*json)[name].isObject() == false && (*json)[name].isArray() == false) {
			return ret;
		}
		ret.reset(new NewJson);
		delete ret->json;
		ret->json = new Json2((*json)[name]);
		return ret;
	} catch (...) {
		return ret;
	}
}

void NewJson::put(const string &name, const char *value)
{
	(*json)[name] = string(value);
}


void NewJson::put(const string &name, const string &value)
{
	try {
		(*json)[name] = value;
	}catch(...){}
}

void NewJson::put(const string &name, const string &name2, const string &value)
{
	if ((*json)[name].isObject() == true) {
		(*json)[name][name2] = value;
		return;
	}
	if ((*json)[name].isNull() == true) {
		Json::Value v;
		v[name2] = value;
		(*json)[name] = v;
	}
}

void NewJson::put(const string &name, NewJson &v)
{
	(*json)[name] = &(*(v.json));
}

void NewJson::put(const string &name, bool v)
{
	(*json)[name] = v;
}

void NewJson::put(const string &name, int v)
{
	try {
		(*json)[name] = boost::lexical_cast<string>(v);
	}catch(...){}
}

void NewJson::put(const string &name, long long v)
{
	try {
		(*json)[name] = boost::lexical_cast<string>(v);
	} catch (...) {}
}

void NewJson::append(const string &name, NewJson &v)
{
	(*json)[name].append(&(*(v.json)));
}

void NewJson::append(const string &name, const string &value)
{
	(*json)[name].append(value);
}

void NewJson::append(const string &name, int value)
{
	try {
		(*json)[name].append(boost::lexical_cast<string>(value));
	}catch(...){}
}

void NewJson::clear(const string &name)
{
	try {
		(*json)[name].clear();
	} catch (...) {}
}

int NewJson::size(const string &name)
{
	int s = 0;
	try {
		s = (*json)[name].size();
	} catch (...) {}
	return s;
}

std::shared_ptr<NewJson> NewJson::element(const string &name, int i)
{
	std::shared_ptr<NewJson> ret(new NewJson());
	try {
		if ((*json)[name].isObject() == false) {
			return ret;
		}
		delete ret->json;
		ret->json = new Json2((*json)[name][i]);
		return ret;
	} catch (...) {
		return ret;
	}
}

void NewJson::append(NewJson &v)
{
	(*json)->append(&(*(v.json)));
}

void NewJson::append(const string &value)
{
	(*json)->append(value);
}

void NewJson::append(int value)
{
	try {
		(*json)->append(boost::lexical_cast<string>(value));
	} catch (...) {}
}

void NewJson::clear()
{
	try {
		(*json)->clear();
	} catch (...) {}
}

int NewJson::size()
{
	int s = 0;
	try {
		s = (*json)->size();
	} catch (...) {}
	return s;
}

std::shared_ptr<NewJson> NewJson::element(int i)
{
	std::shared_ptr<NewJson> ret(new NewJson());
	try {
		if ((*json)->isArray() == false) {
			return ret;
		}
		delete ret->json;
		ret->json = new Json2((*json)->operator[](i));
		return ret;
	} catch (...) {
		return ret;
	}
}

void NewJson::getKeys(vector<string> &keys)
{
	try {
		auto members = (*json)->getMemberNames();
		for (auto iter = members.begin(); iter != members.end(); ++iter) {
			keys.push_back(*iter);
		}
	}catch(...){}

}