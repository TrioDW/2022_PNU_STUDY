const express = require('express')
const res = require('express/lib/response')
const app = express()
const port = 3000

app.use(express.static('public'));

app.get('/webapi', function(req, res) {
    var companyname = req.query.word;
    companyname = encodeURI(companyname);
    var request = require('request');
    var options = {
    'method': 'GET',
    'url': 'http://api.seibro.or.kr/openapi/service/StockSvc/getStkIsinByNmN1?ServiceKey=L4FGPswC%2FnH8LsJ%2B6vrL%2FmSdtf%2BpEV%2BXLt4AEoDo2HuHZNlkjNM7jJb1eqpsjYi2RJ%2FK0RgJrzqRO0HMeSUezg%3D%3D&secnNm=' + companyname,
    'headers': {
    'Cookie': 'WMONID=zvHnEWak8YM'
    }
    };
    request(options, function (error, response) {
        if (error) throw new Error(error);
        console.log(response.body);
        res.send(response.body);
    });
})

app.get('/webapi2', function(req, res) {
    var companynum = req.query.word;
    companynum = encodeURI(companynum);
    var request = require('request');
    var options = {
    'method': 'GET',
    'url': 'http://apis.data.go.kr/1160100/service/GetStocDiviInfoService/getDiviInfo?serviceKey=L4FGPswC%2FnH8LsJ%2B6vrL%2FmSdtf%2BpEV%2BXLt4AEoDo2HuHZNlkjNM7jJb1eqpsjYi2RJ%2FK0RgJrzqRO0HMeSUezg%3D%3D&resultType=xml&pageNo=1&numOfRows=10&stckIssuCmpyNm=' + companynum,
    'headers': {
    'Cookie': 'WMONID=zvHnEWak8YM'
    }
    };
    request(options, function (error, response) {
        if (error) throw new Error(error);
        console.log(response.body);
        res.send(response.body);
    });
})

app.get('/mapapi', function(req, res) {
    request(options, function (error, response) {
        if (error) throw new Error(error);
        console.log(response.body);
        res.send(response.body);
    });
})

app.listen(port, () => console.log(`Example app listening at http://localhost:${port}/project.html`))