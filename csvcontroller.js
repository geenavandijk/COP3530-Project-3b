const bodyParser = require('body-parser');
const Papa = require('papaparse'); // Assuming you intended to use Papaparse for CSV conversion

class CSVController {
    constructor(){}

    createCsv(items) {
        const csv = Papa.unparse(items, {
            header: true,
            encoding: 'UTF-16'
        });
        return csv; 
    }
}

module.exports = CSVController; 



