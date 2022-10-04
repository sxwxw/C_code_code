import 'package:flutter/material.dart';
import 'package:flutter_datetime_picker/flutter_datetime_picker.dart';
import 'package:date_format/date_format.dart';

class timeTwo extends StatefulWidget {
  const timeTwo({Key? key}) : super(key: key);

  @override
  _timeTwoState createState() => _timeTwoState();
}

class _timeTwoState extends State<timeTwo> {
  DateTime nowTime = DateTime.now();
  void _showDate() {
    DatePicker.showDatePicker(context,
        showTitleActions: true,
        minTime: DateTime(1980, 3, 5),
        maxTime: DateTime(2050, 6, 7), onChanged: (date) {
      setState(() {
        nowTime = date;
      });
      // print('change $date');
    }, onConfirm: (date) {
      // print('confirm $date');
      setState(() {
        nowTime = date;
      });
    }, currentTime: DateTime.now(), locale: LocaleType.zh);
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Scaffold(
        appBar: AppBar(title: Text('时间插件')),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              InkWell(
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      formatDate(nowTime, [yyyy, '-', mm, '-', dd]),
                    ),
                  ],
                ),
                onTap: _showDate,
              )
            ],
          ),
        ),
      ),
    );
  }
}
