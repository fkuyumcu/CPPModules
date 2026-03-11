#include "PmergeMe.hpp"

// ── Canonical form ───────────────────────────────────────────────────────────

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other) { vec = other.vec; deq = other.deq; }
    return *this;
}

PmergeMe::~PmergeMe()
{
    
}


// ── Jacobsthal sequence: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2) ─────────────

int PmergeMe::jacobsthal(int n) const
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


// ── Parse & validate: pozitif tam sayıları vec ve deq'e doldurur ────────────

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);

        if (arg.empty() || arg[0] == '-')
            throw std::runtime_error("Error");

        for (size_t j = 0; j < arg.size(); j++)
            if (!isdigit(arg[j]))
                throw std::runtime_error("Error");

        std::istringstream ss(arg);
        int val;
        ss >> val;
        if (val < 0)
            throw std::runtime_error("Error");

        vec.push_back(val);
        deq.push_back(val);
    }
}


// ── Binary search insert: val'ı chain[0..limit) aralığına yerleştirir ───────

void PmergeMe::insertVector(std::vector<int> &chain, int val, int limit)
{
    int lo = 0;
    int hi = limit; 

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (chain[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

// ── Ford-Johnson (merge-insert) sort — std::vector ─────────────────────────

void PmergeMe::sortVector(std::vector<int> &v)
{
    int n = v.size();

    if (n <= 1)
        return;

    int pairs = n / 2;
    bool hasStray = (n % 2 == 1);
    int stray = hasStray ? v[n - 1] : -1;

    std::vector<std::pair<int,int> > paired;
    for (int i = 0; i < pairs; i++)
    {
        int a = v[2 * i];
        int b = v[2 * i + 1];
        if (a < b) std::swap(a, b);
        paired.push_back(std::make_pair(a, b));
    }

    std::vector<int> bigs;
    for (int i = 0; i < pairs; i++)
        bigs.push_back(paired[i].first);

    sortVector(bigs);

    std::vector<int> pend;
    std::vector<bool> used(pairs, false);
    for (int i = 0; i < pairs; i++)
    {
        for (int j = 0; j < pairs; j++)
        {
            if (!used[j] && paired[j].first == bigs[i])
            {
                pend.push_back(paired[j].second);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> chain(bigs);
    chain.insert(chain.begin(), pend[0]);

    std::vector<bool> inserted(pend.size(), false);
    inserted[0] = true;

    int k = 1;
    while (true)
    {
        int jCurr = jacobsthal(k + 1);
        int jPrev = jacobsthal(k);

        if (jPrev >= (int)pend.size())
            break;

        int end   = std::min(jCurr, (int)pend.size()) - 1;
        int start = jPrev;

        for (int i = end; i >= start; i--)
        {
            if (inserted[i])
                continue;

            int limit = 0;
            for (int j = 0; j < (int)chain.size(); j++)
            {
                if (chain[j] == bigs[i])
                {
                    limit = j;
                    break;
                }
            }

            insertVector(chain, pend[i], limit);
            inserted[i] = true;
        }
        k++;
    }

    if (hasStray)
        insertVector(chain, stray, chain.size());

    v = chain;
}

// ── Binary search insert: val'ı chain[0..limit) aralığına yerleştirir ───────

void PmergeMe::insertDeque(std::deque<int> &chain, int val, int limit)
{
    int lo = 0;
    int hi = limit;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (chain[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

// ── Ford-Johnson (merge-insert) sort — std::deque ──────────────────────────

void PmergeMe::sortDeque(std::deque<int> &d)
{
    int n = d.size();

    if (n <= 1)
        return;

    int pairs = n / 2;
    bool hasStray = (n % 2 == 1);
    int stray = hasStray ? d[n - 1] : -1;

    std::deque<std::pair<int,int> > paired;
    for (int i = 0; i < pairs; i++)
    {
        int a = d[2 * i];
        int b = d[2 * i + 1];
        if (a < b) std::swap(a, b);
        paired.push_back(std::make_pair(a, b));
    }

    std::deque<int> bigs;
    for (int i = 0; i < pairs; i++)
        bigs.push_back(paired[i].first);

    sortDeque(bigs);

    std::deque<int> pend;
    std::deque<bool> used(pairs, false);
    for (int i = 0; i < pairs; i++)
    {
        for (int j = 0; j < pairs; j++)
        {
            if (!used[j] && paired[j].first == bigs[i])
            {
                pend.push_back(paired[j].second);
                used[j] = true;
                break;
            }
        }
    }

    std::deque<int> chain(bigs);
    chain.insert(chain.begin(), pend[0]);

    std::deque<bool> inserted(pend.size(), false);
    inserted[0] = true;

    int k = 1;
    while (true)
    {
        int jCurr = jacobsthal(k + 1);
        int jPrev = jacobsthal(k);

        if (jPrev >= (int)pend.size())
            break;

        int end   = std::min(jCurr, (int)pend.size()) - 1;
        int start = jPrev;

        for (int i = end; i >= start; i--)
        {
            if (inserted[i])
                continue;

            int limit = 0;
            for (int j = 0; j < (int)chain.size(); j++)
            {
                if (chain[j] == bigs[i])
                {
                    limit = j;
                    break;
                }
            }

            insertDeque(chain, pend[i], limit);
            inserted[i] = true;
        }
        k++;
    }

    if (hasStray)
        insertDeque(chain, stray, chain.size());

    d = chain;
}


// ── Giriş noktası: parse → sort → çıktı ────────────────────────────────────

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");

    std::clock_t vStart = std::clock();
    sortVector(vec);
    std::clock_t vEnd = std::clock();

    std::clock_t dStart = std::clock();
    sortDeque(deq);
    std::clock_t dEnd = std::clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");

    double vTime = (double)(vEnd - vStart) / CLOCKS_PER_SEC * 1e6;
    double dTime = (double)(dEnd - dStart) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << dTime << " us" << std::endl;
}