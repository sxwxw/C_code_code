import 'package:flutter/material.dart';

class farm extends StatefulWidget {
  const farm({Key? key}) : super(key: key);

  @override
  _farmState createState() => _farmState();
}

class _farmState extends State<farm> {
  // final _userName = TextEditingController();//初始化赋值
  late String _userName;
  late String _password;
  // @override
  // void initState() {
  //   super.initState();
  //   _userName.text = 'wxw';
  // }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('表单'),
      ),
      body: Padding(
        padding: EdgeInsets.all(10),
        child: Column(
          children: <Widget>[
            TextField(
              decoration: const InputDecoration(
                hintText: '请输入用户名',
                border: OutlineInputBorder(),
              ),
              onChanged: (value) {
                setState(() {
                  _userName = value;
                });
              },
            ),
            SizedBox(height: 40),
            TextField(
              obscureText: true,
              decoration: const InputDecoration(
                hintText: '密码',
                border: OutlineInputBorder(),
                labelText: '用户名',
              ),
              onChanged: (value) {
                setState(() {
                  _password = value;
                });
              },
            ),
            ElevatedButton(
              onPressed: () {
                print(_userName);
                print(_password);
              },
              child: Text('获取'),
            )
          ],
        ),
      ),
    );
  }
}

class DemoOne extends StatelessWidget {
  const DemoOne({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: EdgeInsets.all(20),
      child: Column(
        children: const <Widget>[
          TextField(),
          SizedBox(
            height: 20,
          ),
          TextField(
            decoration: InputDecoration(
              hintText: '单行文本框',
              border: OutlineInputBorder(),
            ),
          ),
          SizedBox(
            height: 20,
          ),
          TextField(
            maxLines: 4,
            decoration: InputDecoration(
              hintText: '多行文本框',
              border: OutlineInputBorder(),
            ),
          ),
          SizedBox(
            height: 20,
          ),
          TextField(
            obscureText: true,
            decoration: InputDecoration(
              // hintText: '单行文本框',
              border: OutlineInputBorder(),
              icon: Icon(Icons.people),
              labelText: '用户名',
            ),
          ),
        ],
      ),
    );
  }
}
