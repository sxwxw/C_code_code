let ajaxtimes =0;
export  const request = (params)=>{
    // 定义公共的url
    const baseurl = 'https://api-hmugo-web.itheima.net/api/public/v1';
    return new Promise((resolve,reject)=>{
        ajaxtimes++;
        // 显示加载刷新效果
        wx.showLoading({
            title: '加载中，请稍后',
            mask: true,
        });
        var reqTask = wx.request({
           ...params,
           url:baseurl+params.url,
            success:(result)=>{
                resolve(result.data.message);
            },
            fail:(err)=>{
                reject(err);
            },
            complete: function() {
                ajaxtimes--;
                if(ajaxtimes===0)
                {
                    wx.hideLoading();
                }
                
            }
        });
    })
}
// Promise接受一个「函数」作为参数，该函数的两个参数分别是resolve和reject。这两个函数就是就是「回调函数」

// resolve函数的作用：在异步操作成功时调用，并将异步操作的结果，作为参数传递出去；

// reject函数的作用：在异步操作失败时调用，并将异步操作报出的错误，作为参数传递出去。