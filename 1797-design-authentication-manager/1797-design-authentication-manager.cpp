class AuthenticationManager {
public:
    unordered_map<string,int>tokens;
    int timetoLive;
    AuthenticationManager(int timeTolive) {
        timetoLive = timeTolive;
    }
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime;
        return;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokens.count(tokenId)){
            // Checking wether token is Expired or not..
            if(tokens[tokenId]+timetoLive>currentTime){
                tokens[tokenId] = currentTime;
            }
        }
        return;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int unexpiredToken = 0;
        for(auto token:tokens){
            int expiry = token.second+timetoLive;
            if(expiry>currentTime) unexpiredToken++;
        }
        return unexpiredToken;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */