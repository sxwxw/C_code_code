//Component Object
Component({
    // 该处接收父组件传递的数据
    properties: {
        tabs:{
            // type 要接收数据的类型
            type:Array,
            // value 要接收的默认值
            value:[]
        }
    },
    data: {
    },
    methods: {
        listTap(e){
            const index = e.currentTarget.dataset.index;
            // 在子组件自定义一个事件
            this.triggerEvent("fdz",index);
            // 解构赋值
            // console.log(this);
            // console.log(this.data);
            // let {tabs}=this.data;
            // // console.log({tabs});
            // // console.log(tabs);
            // // v是每一个循环项相当于item
            // tabs.forEach((v,i)=>i===index?v.isActive=true:v.isActive=false)
            // this.setData({
            //     tabs
            // })
        }
    }
});