using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Net;
using System.Net.Mail;
using System.IO;
using System.Threading;


namespace MailSender
{
    public partial class MailSender : Form
    {
        //add 1 file
        Attachment attach = null;

        bool check = true;
        bool checkRD = true;
        string ChuoiNguoiDungNhap;

        //Mở rộng thêm nhiều file
        //Attachment[] mangAttach = null;
        //OpenFileDialog dlg = new OpenFileDialog();
        //string[] DanhSachFile = new string[10];

        public MailSender()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        void Send(string from, string to, string subject, string message, Attachment file = null)
        //send new
        //void Send(string from, string to, string subject, string message, Attachment[] file = null)
        {
            MailMessage mail = new MailMessage(from, to, subject, message);
            SmtpClient client = new SmtpClient();
           client.Host = "txbSmtpServer.Text";
            client.Port = 587;
            client.EnableSsl = true;

            //client.Port = 25;
            //client.DeliveryMethod = SmtpDeliveryMethod.Network;
            //client.UseDefaultCredentials = false;

            client.Credentials = new NetworkCredential(txbUsername.Text, txbPassword.Text);

            if (attach != null)
            {
                mail.Attachments.Add(attach);
            }

            //if (mangAttach.Length > 0)
            //{
            //    for (int i = 0; i < mangAttach.Length; i++)
            //    {
            //        // ??
            //        mail.Attachments.Add(mangAttach[i]);
            //    }

            //}

            client.Send(mail);

        }
        private void btnLogin_Click(object sender, EventArgs e)
        {
            string str = "toni.hai.sun@gmail.com";
            try
            {
                Send(txbUsername.Text, str, "", "");
            }
            catch (Exception)
            {
                check = false;
            }

            if (check)
            {
                MessageBox.Show("Đăng nhập thành công", "Login", MessageBoxButtons.OK);
                txbSubject.ReadOnly = false;
                txbMessage.ReadOnly = false;
                btnLogin.Enabled = false;
                btnMailList.Enabled = true;
                btnAddFile.Enabled = true;
                btnSend.Enabled = true;
                txbTo.ReadOnly = false;
                rdListMail.Enabled = true;
                radioButton2.Enabled = true;

                txbSmtpServer.ReadOnly = true;
                txbUsername.ReadOnly = true;
                txbPassword.ReadOnly = true;
            }
            else
            {
                MessageBox.Show("Đăng nhập thất bại", "Login", MessageBoxButtons.OK);
            }

        }

        private void btnMailList_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                txbTo.Text = dialog.FileName;
                txbTo.ReadOnly = true;
            }
        }

        private void btnAddFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                txbFile.Text = dialog.FileName;
            }


            //OpenFileDialog dlg = new OpenFileDialog();
            //dlg.Multiselect = true;

            //// string[] result = dialog.FileNames;

            //if (dlg.ShowDialog() == DialogResult.OK)
            //{
            //    int i = 0;
            //    foreach (string str in dlg.FileNames)
            //    {
            //        //DanhSachFile[i] = str;
            //        //MessageBox.Show(DanhSachFile[i]);
            //        i++;
            //    }

            //    DanhSachFile = new string[i];
            //    i = 0;
            //    foreach (string str in dlg.FileNames)
            //    {
            //        DanhSachFile[i] = str;
            //        //MessageBox.Show(DanhSachFile[i]);
            //        i++;
            //    }
            //}
        }
        

        private void btnSend_Click(object sender, EventArgs e)
        {
            Thread thread = new Thread(() =>
            {
                try
                {
                    attach = new Attachment(txbFile.Text);

                    //if (DanhSachFile.Length > 0)
                    //{
                    //    for (int i = 0; i < DanhSachFile.Length; i++)
                    //    {
                    //        mangAttach[i] = new Attachment(DanhSachFile[i]);
                    //    }
                    //}

                    //StreamReader sr = new StreamReader(txbTo.Text);
                    string result, result1;

                    // Xử lý chuỗi mail người dùng nhập
                    //string[] DSMail = ChuoiNguoiDungNhap.Split(new char[] { ';' });
                    //for (int i = 0; i < DSMail.Length; i++)
                    //{
                    //    Send(txbUsername.Text, DSMail[i], txbSubject.Text, txbMessage.Text, attach);
                    //}
                    if (checkRD == false)
                    {
                        StreamReader strd = new StreamReader(@"C:\Users\Hai\Desktop\MailSender\List.txt");
                        while ((result1 = strd.ReadLine()) != null)
                        {
                            Send(txbUsername.Text, result1, txbSubject.Text, txbMessage.Text, attach);
                        }
                        MessageBox.Show("Gửi mail thành công", "Mail Sender", MessageBoxButtons.OK);
                        strd.Close();
                    }
                    else
                    {
                        StreamReader sr = new StreamReader(txbTo.Text);
                        while ((result = sr.ReadLine()) != null)
                        {
                            Send(txbUsername.Text, result, txbSubject.Text, txbMessage.Text, attach);
                        }
                        MessageBox.Show("Gửi mail thành công", "Mail Sender", MessageBoxButtons.OK);
                        sr.Close();
                    }


                }
                catch (Exception)
                {
                    MessageBox.Show("Không thể gửi mail", "Mail Sender", MessageBoxButtons.OK);
                    check = false;
                }
            }
            );

            thread.Start();
        }

        private void txbSubject_TextChanged(object sender, EventArgs e)
        {

        }

        private void lbSmtpsSrver_Click(object sender, EventArgs e)
        {

        }

        private void txbMailNhap_TextChanged(object sender, EventArgs e)
        {

        }

        //
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            txbNhapMail.ReadOnly = true;
            txbTo.ReadOnly = false;

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            txbTo.ReadOnly = true;
            txbNhapMail.ReadOnly = false;
            checkRD = false;
        }

        private void txbNhapMail_TextChanged(object sender, EventArgs e)
        {

        }

        private void txbNhapMail_MouseDown(object sender, MouseEventArgs e)
        {

        }

        private void txbNhapMail_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                ChuoiNguoiDungNhap = txbNhapMail.Text;
                txbNhapMail.ReadOnly = true;
                System.IO.FileStream fs = new System.IO.FileStream(@"C:\Users\Hai\Desktop\MailSender\List.txt", FileMode.Create, FileAccess.Write, FileShare.None);
                StreamWriter sw = new StreamWriter(fs);

                // Xử lý chuỗi người dùng nhập
                string[] DSMail = ChuoiNguoiDungNhap.Split(new char[] { ';' });
                foreach (string str in DSMail)
                {
                    sw.WriteLine(str);
                }
                sw.Flush();
                sw.Close();
                fs.Close();

                /*
                // Đọc thử
                StreamReader strm = new StreamReader(@"C:\Users\Hai\Desktop\MailSender\List.txt");
                string strdoc;
                while ((strdoc = strm.ReadLine()) != null)
                {
                    MessageBox.Show(strdoc);   
                }
                strm.Close();
                */
                //for (int i = 0; i < DSMail.Length; i++)
                //{
                //    Send(txbUsername.Text, DSMail[i], txbSubject.Text, txbMessage.Text, attach);
                //}


                //char[] chr = new char[';'];
                //string[] DSMail = ChuoiNguoiDungNhap.Split(new char[] { ';' });
                //MessageBox.Show(DSMail[]);

            }
        }

        private void txbTo_TextChanged(object sender, EventArgs e)
        {

        }

    }
}

/*
    Video: https://www.youtube.com/watch?v=eibGHUImsCA
    ------------------------------------
    Gmail
    Outgoing Mail (SMTP) Server
        Server - smtp.gmail.com
        Port - 587
        Requires SSL - Yes
        https://support.google.com/a/answer/176600?hl=en
        https://www.google.com/settings/security/lesssecureapps
 
    ------------------------------------
    Yahoo!
    Outgoing Mail (SMTP) Server
        Server - smtp.mail.yahoo.com
        Port - 587
        Requires SSL - Yes
        https://help.yahoo.com/kb/SLN4724.html
 
    ------------------------------------
    Outlook
    Outgoing Mail (SMTP) Server
        Server - smtp.live.com
        Port - 587
        Requires SSL - Yes
        https://www.outlook-apps.com/outlook-com-pop-settings/

*/