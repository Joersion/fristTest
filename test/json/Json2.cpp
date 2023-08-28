#include "Json2.h"
#include <memory>
using std::unique_ptr;

Json2::Json2(const string &str)
{
	Json::CharReaderBuilder builder;
	std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
	if (!reader->parse(str.c_str(), str.c_str()+ str.size(), &json, &errs)) {
		printf("errs:[%s], %s\n", str.c_str(), errs.c_str());
		//json.reset(0);
	}
}

Json2::Json2()
{
}

Json2::Json2(const Json::Value &v)
{
	json = v;
}

const string & Json2::getError()
{
	return errs;
}

string Json2::toString()
{
	//return this->json.toStyledString();
	Json::StreamWriterBuilder  builder;
	builder.settings_["indentation"] = "";
	return Json::writeString(builder, json);
}

string Json2::toString(Json::Value& json)
{
	//return json.toStyledString();
	Json::StreamWriterBuilder  builder;
	builder.settings_["indentation"] = "";
	return Json::writeString(builder, json);
}
