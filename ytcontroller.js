const {google} = require('googleapis');

const API_KEY = "AIzaSyCBwhSvTPKw5qCcEVd4DccL8I7ReScGfYs";
class YTController {
    constructor() {
        this.controller = google.youtube({
            version: 'v3',
            auth: API_KEY // using API key as authorization and specifying version 3 
        });       
        
        this.curItems = ''; 
    }

    async searchResults(queryString) {
        // Youtube query.
        const res = await this.controller.search.list({
            part: 'id, snippet', 
            q: queryString,
            maxResults: 50
        });

        const items = res.data.items; 
        // console.log(items);

        // Parse the results and construct an object with {videoId and videoTitle}
        const data = [];
        items.forEach(i => {
            // Filter out only youtube videos.
           
            if (i.id.kind === 'youtube#video') {
                data.push({
                    vId: i.id.videoId,
                    vTitle: i.snippet.title
                });
            }
        });

        // Save the current items in memory, so we can use them for constructing 
        // our csv file.
        this.curItems = data; 
    
        return Promise.resolve({
            maxResults: res.data.pageInfo.totalResults,
            items: data
        });
    }
};

module.exports = YTController;



