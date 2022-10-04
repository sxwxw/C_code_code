export const request = (params)=>{
    return new Promise((resolve,reject)=>{
        const baseurl ='https://wxapi.wuwuwu223.cn';
        wx.request({
            url: baseurl+params.url,
            data: params.data||{},
            method: params.method||'GET',
            success: function(res){
                resolve(res);
            },
            fail: function(err) {
                reject(err);
            }
        })
    })
}
