#include <string>
#include <iostream>

class StringView {
    std::string &s;
    size_t vbegin{}, count{};
public:
    StringView(std::string &s_, size_t begin_ = 0, size_t count_ = std::string::npos) : 
        s(s_), 
        vbegin(std::min(begin_, s.size())), 
        count(std::min(count_, s.size() - vbegin))
    {}

    StringView(const StringView &sv, size_t begin_ = 0, size_t count_ = std::string::npos) :
        s(sv.s),
        vbegin(std::min(sv.vbegin + begin_, (sv.vbegin + sv.count))),
        count(std::min(count_, (sv.vbegin + sv.count) - vbegin))
    {}

    size_t length() const {
        return count;
    }

    size_t size() const {
        return count;
    }

    std::string str(size_t begin_ = 0, size_t count_ = std::string::npos) const {
        if (begin_ >= count) {
            return "";
        }
        return s.substr(vbegin + begin_, std::max(size_t(0), std::min(count - begin_, count_)));
    }

    const char& operator[] (size_t index) const {
        return s[vbegin + index];
    }

    char& operator[] (size_t index) {
        return s[vbegin + index];
    }

    const char& at(size_t index) const {
        if (index < count) {
            return s[vbegin + index];
        } else {
            throw std::out_of_range("Out of StringView bounds");
        }
    }

    char& at(size_t index) {
        if (index < count) {
            return s[vbegin + index];
        } else {
            throw std::out_of_range("Out of StringView bounds");
        }
    }
    
    friend auto operator<=> (const StringView &sv_1, const StringView &sv_2) {
        auto current_sv = sv_1.str();
        auto another_sv = sv_2.str(); 
        if (current_sv < another_sv) {
            return std::strong_ordering::less;
        } else if (current_sv == another_sv) {
            return std::strong_ordering::equal;
        } else {
            return std::strong_ordering::greater;
        } 
    }

    friend auto  operator== (const StringView &sv_1, const StringView &sv_2) {
        return sv_1.str() == sv_2.str();
    }

//Class iterators
    using iterator = std::string::iterator;
    using const_iterator = std::string::const_iterator;
    using reverse_iterator = std::string::reverse_iterator;
    using const_reverse_iterator = std::string::const_reverse_iterator;

    auto begin() const {
        return s.begin() + vbegin;
    }

    auto end() const {
        return s.begin() + vbegin + count;
    }

    auto rbegin() const {
        return std::make_reverse_iterator(end());
    }

    auto rend() const {
        return std::make_reverse_iterator(begin());
    }

    auto cbegin() const {
        return s.cbegin() + vbegin;
    }

    auto cend() const {
        return s.cbegin() + vbegin + count;
    }

    auto crbegin() const {
        return std::make_reverse_iterator(cend());
    }

    auto crend() const {
        return std::make_reverse_iterator(cbegin());
    }
};
