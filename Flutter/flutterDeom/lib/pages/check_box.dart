import 'package:flutter/material.dart';

class checkall extends StatefulWidget {
  const checkall({Key? key}) : super(key: key);

  @override
  _checkallState createState() => _checkallState();
}

class _checkallState extends State<checkall> {
  bool flag = true;
  int sex = 1;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('checkbox'),
      ),
      body: Column(
        children: [
          Row(
            children: [
              Text(flag ? '男' : '女'),
              Checkbox(
                value: flag,
                onChanged: (value) {
                  setState(() {
                    flag = value!;
                  });
                },
              ),
            ],
          ),
          CheckboxListTile(
            value: flag,
            onChanged: (value) {
              setState(() {
                flag = value!;
              });
            },
            title: Text('标题'),
            subtitle: Text('二级标题'),
          ),
          Row(
            children: <Widget>[
              Text('篮球'),
              Radio(
                value: 1,
                groupValue: sex,
                onChanged: (value) {
                  setState(() {
                    sex = value as int;
                  });
                },
              ),
              Text('篮球'),
              Radio(
                value: 2,
                groupValue: sex,
                onChanged: (value) {
                  setState(() {
                    sex = value as int;
                  });
                },
              ),
              Text('篮球'),
              Radio(
                value: 3,
                groupValue: sex,
                onChanged: (value) {
                  setState(() {
                    sex = value as int;
                  });
                },
              )
            ],
          ),
          RadioListTile(
            value: 1,
            onChanged: (value) {
              setState(() {
                sex = value as int;
              });
            },
            groupValue: sex,
            title: Text('一级标题'),
            subtitle: Text('二级标题'),
            secondary: Icon(Icons.help),
            selected: sex == 1,
          ),
          Switch(
              value: flag,
              onChanged: (value) {
                setState(() {
                  flag = value;
                });
              })
        ],
      ),
    );
  }
}
