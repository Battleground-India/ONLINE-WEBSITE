const std::string BOT_TOKEN = "8571748808:AAFbNDineI06NO-LOJSxcviatyA7IB2nxy0"
const std::string CHAT_ID = "@Ultimatelyx_Bot"
void sendTelegramMessage(std::string msg) {
    const size_t MAX_MESSAGE_LENGTH = 4096;
    while (msg.length() > 0) {
        std::string part = msg.substr(0, MAX_MESSAGE_LENGTH);
        msg.erase(0, MAX_MESSAGE_LENGTH);
        CURL* curl;
        CURLcode res;
        const std::string url = "https://api.telegram.org/bot" + BOT_TOKEN + "/sendMessage?chat_id=" + CHAT_ID + "&text=" + curl_easy_escape(curl, part.c_str(), part.length());
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            } else {
                std::cout << "Message part sent successfully!" << std::endl;
            }
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }
}

