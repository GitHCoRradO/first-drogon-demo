#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class User : public drogon::HttpController<User> {
public:
    METHOD_LIST_BEGIN
        // use METHOD_ADD to add your custom processing function here;
        METHOD_ADD(User::login, "/token?userId={1}&passwd={2}",
                   Post);  // url:  http://127.0.0.1:8888/User/token?userId={1}&passwd={2}
        METHOD_ADD(User::getInfo, "/{1}/info?token={2}",
                   Get);          // url:  http://127.0.0.1:8888/User/{1}/info?token={2}
    METHOD_LIST_END

    // your declaration of processing function maybe like this:
    void login(const HttpRequestPtr &req,
               std::function<void(const HttpResponsePtr &)> &&callback,
               std::string &&userId,
               const std::string &password);

    void getInfo(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string userId,
                 const std::string &token) const;
};
