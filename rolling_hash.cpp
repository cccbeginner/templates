//rolling hash
class strhash{
	private:
		vector<long long> hash, pows;
		const long long mod = 1073676287;
	public:
		strhash(string s, int prm=0xdefaced){
			hash.emplace_back(0);
			pows.emplace_back(1);
			for(unsigned i = 0; i < s.size(); ++i){
				hash.emplace_back((hash.back()*prm+s[i])%mod);
				pows.emplace_back(pows.back()*prm%mod);
			}
		}
		strhash(char *c, int prm=0xdefaced){
			hash.emplace_back(0);
			pows.emplace_back(1);
			for(int i = 0; c[i] != '\0'; ++i){
				hash.emplace_back((hash.back()*prm+c[i])%mod);
				pows.emplace_back(pows.back()*prm%mod);
			}
		}
		long long gethash(int l, int r){//[l,r)
			return (hash[r]+mod-hash[l]*pows[r-l]%mod)%mod;
		}
};
