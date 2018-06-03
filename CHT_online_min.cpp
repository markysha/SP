const ll MAX = (1e15);
const ll Q = -(1LL << 62);

struct Line {
    ll k, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &to) const {
        if (to.b != -MAX)
            return k < to.k;
        const Line *cur = succ();
        if (!cur)
            return false;
        return b - cur->b < (ld)(cur->k - k) * to.k;
    }
};

struct CHT : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end())
                return false;
            return y->k == z->k && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end())
            return y->k == x->k && y->b <= x->b;
        return (ld)(x->b - y->b) * (z->k - y->k) >= (ld)(y->b - z->b) * (y->k - x->k);
    }

    void insertLine(ll k, ll b) {
        auto cur = insert({-k, -b});
        cur->succ = [=] { return next(cur) == end() ? 0 : &*next(cur); };
        if (bad(cur)) {
            erase(cur);
            return;
        }
        while (next(cur) != end() && bad(next(cur)))
            erase(next(cur));
        while (cur != begin() && bad(prev(cur)))
            erase(prev(cur));
    }

    ll findMin(ll x) {
        x = -x;
        auto best = *lower_bound({-x, -MAX});
        return best.k * x - best.b;
    }
};
