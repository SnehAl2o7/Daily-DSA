class Spreadsheet {
private:
    int rows;
    int cols = 26;
    vector<vector<int>> grid;
public:
    Spreadsheet(int row) : rows(row), grid(rows,vector<int>(cols,0)) {}
    
    void setCell(const string& cell, int value) {
        auto [rowI, colI] = getCellIndices(cell);
        if (isValidCell(rowI, colI)) {
            grid[rowI][colI] = value;
        }
    }
    
     void resetCell(const string& cell) {
        auto [rowI, colI] = getCellIndices(cell);
        if (isValidCell(rowI, colI)) {
            grid[rowI][colI] = 0;
        }
    }

    int getCell(const string& cell) {
        auto [rowI, colI] = getCellIndices(cell);
        if (isValidCell(rowI, colI)) {
            return grid[rowI][colI];
        }
        return 0;
    }
    
    int getValue(const string& f) {
        if (f.empty() || f[0] != '=') return 0;

        string exp = f.substr(1);
        return evaluateExpression(exp);
    }

private:
pair<int, int> getCellIndices(const string& cell) {
        int colI = cell[0] - 'A';
        int rowI = 0, i = 1;

        while (i < cell.size() && isdigit(cell[i])) {
            rowI = rowI * 10 + (cell[i] - '0');
            i++;
        }
        return {rowI - 1, colI};
    }

    bool isValidCell(int row, int col) {
        return (row >= 0 && row < rows && col >= 0 && col < cols);
    }

    int evaluateExpression(const string& exp) {
        int result = 0, num = 0;
        char op = '+';
        string term;

        for (char c : exp + "+") { // Adding a '+' at the end to process last term
            if (isdigit(c) || isalpha(c)) {
                term += c;
            } else if (c == '+' || c == '-') {
                if (!term.empty()) {
                    int value = evaluateTerm(term);
                    result = (op == '+') ? result + value : result - value;
                    term.clear();
                }
                op = c;
            }
        }
        return result;
    }

    int evaluateTerm(const string& term) {
        if (isalpha(term[0])) {
            return getCell(term);
        } else {
            return stoi(term);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
