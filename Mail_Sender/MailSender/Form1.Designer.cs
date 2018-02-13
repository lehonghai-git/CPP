namespace MailSender
{
    partial class MailSender
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lbSmtpsSrver = new System.Windows.Forms.Label();
            this.lbUsername = new System.Windows.Forms.Label();
            this.lbPassword = new System.Windows.Forms.Label();
            this.lbTo = new System.Windows.Forms.Label();
            this.lbSubject = new System.Windows.Forms.Label();
            this.lbFile = new System.Windows.Forms.Label();
            this.lbMessage = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnLogin = new System.Windows.Forms.Button();
            this.txbPassword = new System.Windows.Forms.TextBox();
            this.txbUsername = new System.Windows.Forms.TextBox();
            this.txbSmtpServer = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.rdListMail = new System.Windows.Forms.RadioButton();
            this.txbNhapMail = new System.Windows.Forms.TextBox();
            this.btnMailList = new System.Windows.Forms.Button();
            this.btnAddFile = new System.Windows.Forms.Button();
            this.txbSubject = new System.Windows.Forms.TextBox();
            this.txbFile = new System.Windows.Forms.TextBox();
            this.txbMessage = new System.Windows.Forms.TextBox();
            this.txbTo = new System.Windows.Forms.TextBox();
            this.btnSend = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbSmtpsSrver
            // 
            this.lbSmtpsSrver.AutoSize = true;
            this.lbSmtpsSrver.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbSmtpsSrver.Location = new System.Drawing.Point(25, 33);
            this.lbSmtpsSrver.Name = "lbSmtpsSrver";
            this.lbSmtpsSrver.Size = new System.Drawing.Size(112, 21);
            this.lbSmtpsSrver.TabIndex = 0;
            this.lbSmtpsSrver.Text = "SMTP Server";
            this.lbSmtpsSrver.Click += new System.EventHandler(this.lbSmtpsSrver_Click);
            // 
            // lbUsername
            // 
            this.lbUsername.AutoSize = true;
            this.lbUsername.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbUsername.Location = new System.Drawing.Point(53, 116);
            this.lbUsername.Name = "lbUsername";
            this.lbUsername.Size = new System.Drawing.Size(84, 21);
            this.lbUsername.TabIndex = 1;
            this.lbUsername.Text = "Username";
            this.lbUsername.Click += new System.EventHandler(this.label2_Click);
            // 
            // lbPassword
            // 
            this.lbPassword.AutoSize = true;
            this.lbPassword.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbPassword.Location = new System.Drawing.Point(53, 159);
            this.lbPassword.Name = "lbPassword";
            this.lbPassword.Size = new System.Drawing.Size(84, 21);
            this.lbPassword.TabIndex = 2;
            this.lbPassword.Text = "Password";
            this.lbPassword.Click += new System.EventHandler(this.label3_Click);
            // 
            // lbTo
            // 
            this.lbTo.AutoSize = true;
            this.lbTo.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbTo.Location = new System.Drawing.Point(104, 70);
            this.lbTo.Name = "lbTo";
            this.lbTo.Size = new System.Drawing.Size(31, 21);
            this.lbTo.TabIndex = 3;
            this.lbTo.Text = "To";
            this.lbTo.Click += new System.EventHandler(this.label4_Click);
            // 
            // lbSubject
            // 
            this.lbSubject.AutoSize = true;
            this.lbSubject.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbSubject.Location = new System.Drawing.Point(69, 234);
            this.lbSubject.Name = "lbSubject";
            this.lbSubject.Size = new System.Drawing.Size(66, 21);
            this.lbSubject.TabIndex = 4;
            this.lbSubject.Text = "Subject";
            // 
            // lbFile
            // 
            this.lbFile.AutoSize = true;
            this.lbFile.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbFile.Location = new System.Drawing.Point(98, 294);
            this.lbFile.Name = "lbFile";
            this.lbFile.Size = new System.Drawing.Size(37, 21);
            this.lbFile.TabIndex = 5;
            this.lbFile.Text = "File";
            // 
            // lbMessage
            // 
            this.lbMessage.AutoSize = true;
            this.lbMessage.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.lbMessage.Location = new System.Drawing.Point(60, 363);
            this.lbMessage.Name = "lbMessage";
            this.lbMessage.Size = new System.Drawing.Size(75, 21);
            this.lbMessage.TabIndex = 6;
            this.lbMessage.Text = "Message";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.btnLogin);
            this.groupBox1.Controls.Add(this.txbPassword);
            this.groupBox1.Controls.Add(this.txbUsername);
            this.groupBox1.Controls.Add(this.txbSmtpServer);
            this.groupBox1.Controls.Add(this.lbPassword);
            this.groupBox1.Controls.Add(this.lbUsername);
            this.groupBox1.Controls.Add(this.lbSmtpsSrver);
            this.groupBox1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.groupBox1.Location = new System.Drawing.Point(12, 11);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(738, 206);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Login";
            // 
            // btnLogin
            // 
            this.btnLogin.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btnLogin.Location = new System.Drawing.Point(529, 49);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(139, 70);
            this.btnLogin.TabIndex = 6;
            this.btnLogin.Text = "Login";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);
            // 
            // txbPassword
            // 
            this.txbPassword.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbPassword.Location = new System.Drawing.Point(184, 156);
            this.txbPassword.Name = "txbPassword";
            this.txbPassword.PasswordChar = '*';
            this.txbPassword.Size = new System.Drawing.Size(300, 29);
            this.txbPassword.TabIndex = 5;
            // 
            // txbUsername
            // 
            this.txbUsername.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbUsername.Location = new System.Drawing.Point(184, 113);
            this.txbUsername.Name = "txbUsername";
            this.txbUsername.Size = new System.Drawing.Size(300, 29);
            this.txbUsername.TabIndex = 4;
            // 
            // txbSmtpServer
            // 
            this.txbSmtpServer.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbSmtpServer.Location = new System.Drawing.Point(184, 33);
            this.txbSmtpServer.Name = "txbSmtpServer";
            this.txbSmtpServer.Size = new System.Drawing.Size(300, 29);
            this.txbSmtpServer.TabIndex = 3;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Controls.Add(this.radioButton2);
            this.groupBox2.Controls.Add(this.rdListMail);
            this.groupBox2.Controls.Add(this.txbNhapMail);
            this.groupBox2.Controls.Add(this.btnMailList);
            this.groupBox2.Controls.Add(this.btnAddFile);
            this.groupBox2.Controls.Add(this.txbSubject);
            this.groupBox2.Controls.Add(this.txbFile);
            this.groupBox2.Controls.Add(this.txbMessage);
            this.groupBox2.Controls.Add(this.txbTo);
            this.groupBox2.Controls.Add(this.lbMessage);
            this.groupBox2.Controls.Add(this.lbFile);
            this.groupBox2.Controls.Add(this.lbSubject);
            this.groupBox2.Controls.Add(this.lbTo);
            this.groupBox2.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.groupBox2.Location = new System.Drawing.Point(14, 246);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(736, 550);
            this.groupBox2.TabIndex = 8;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Message";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(178, 185);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(364, 21);
            this.label1.TabIndex = 17;
            this.label1.Text = "VD: mail1@gmail.com;mail2@outlook.com . . .";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Enabled = false;
            this.radioButton2.Location = new System.Drawing.Point(182, 113);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(151, 25);
            this.radioButton2.TabIndex = 16;
            this.radioButton2.Text = "Nhập Danh sách";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // rdListMail
            // 
            this.rdListMail.AutoSize = true;
            this.rdListMail.Checked = true;
            this.rdListMail.Enabled = false;
            this.rdListMail.Location = new System.Drawing.Point(182, 36);
            this.rdListMail.Name = "rdListMail";
            this.rdListMail.Size = new System.Drawing.Size(152, 25);
            this.rdListMail.TabIndex = 15;
            this.rdListMail.TabStop = true;
            this.rdListMail.Text = "Chọn Danh sách";
            this.rdListMail.UseVisualStyleBackColor = true;
            this.rdListMail.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // txbNhapMail
            // 
            this.txbNhapMail.Location = new System.Drawing.Point(182, 144);
            this.txbNhapMail.Name = "txbNhapMail";
            this.txbNhapMail.ReadOnly = true;
            this.txbNhapMail.Size = new System.Drawing.Size(300, 29);
            this.txbNhapMail.TabIndex = 14;
            this.txbNhapMail.TextChanged += new System.EventHandler(this.txbNhapMail_TextChanged);
            this.txbNhapMail.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txbNhapMail_KeyDown);
            this.txbNhapMail.MouseDown += new System.Windows.Forms.MouseEventHandler(this.txbNhapMail_MouseDown);
            // 
            // btnMailList
            // 
            this.btnMailList.Enabled = false;
            this.btnMailList.Location = new System.Drawing.Point(527, 60);
            this.btnMailList.Name = "btnMailList";
            this.btnMailList.Size = new System.Drawing.Size(139, 41);
            this.btnMailList.TabIndex = 13;
            this.btnMailList.Text = "Mail List";
            this.btnMailList.UseVisualStyleBackColor = true;
            this.btnMailList.Click += new System.EventHandler(this.btnMailList_Click);
            // 
            // btnAddFile
            // 
            this.btnAddFile.Enabled = false;
            this.btnAddFile.Location = new System.Drawing.Point(527, 284);
            this.btnAddFile.Name = "btnAddFile";
            this.btnAddFile.Size = new System.Drawing.Size(139, 41);
            this.btnAddFile.TabIndex = 12;
            this.btnAddFile.Text = "Add File";
            this.btnAddFile.UseVisualStyleBackColor = true;
            this.btnAddFile.Click += new System.EventHandler(this.btnAddFile_Click);
            // 
            // txbSubject
            // 
            this.txbSubject.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbSubject.Location = new System.Drawing.Point(182, 231);
            this.txbSubject.Name = "txbSubject";
            this.txbSubject.ReadOnly = true;
            this.txbSubject.Size = new System.Drawing.Size(300, 29);
            this.txbSubject.TabIndex = 10;
            this.txbSubject.TextChanged += new System.EventHandler(this.txbSubject_TextChanged);
            // 
            // txbFile
            // 
            this.txbFile.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbFile.Location = new System.Drawing.Point(182, 291);
            this.txbFile.Name = "txbFile";
            this.txbFile.ReadOnly = true;
            this.txbFile.Size = new System.Drawing.Size(300, 29);
            this.txbFile.TabIndex = 9;
            // 
            // txbMessage
            // 
            this.txbMessage.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbMessage.Location = new System.Drawing.Point(182, 350);
            this.txbMessage.Multiline = true;
            this.txbMessage.Name = "txbMessage";
            this.txbMessage.ReadOnly = true;
            this.txbMessage.Size = new System.Drawing.Size(300, 185);
            this.txbMessage.TabIndex = 8;
            this.txbMessage.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // txbTo
            // 
            this.txbTo.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.txbTo.Location = new System.Drawing.Point(182, 67);
            this.txbTo.Name = "txbTo";
            this.txbTo.ReadOnly = true;
            this.txbTo.Size = new System.Drawing.Size(300, 29);
            this.txbTo.TabIndex = 7;
            this.txbTo.TextChanged += new System.EventHandler(this.txbTo_TextChanged);
            // 
            // btnSend
            // 
            this.btnSend.Enabled = false;
            this.btnSend.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.btnSend.Location = new System.Drawing.Point(257, 807);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(181, 51);
            this.btnSend.TabIndex = 9;
            this.btnSend.Text = "Send";
            this.btnSend.UseVisualStyleBackColor = true;
            this.btnSend.Click += new System.EventHandler(this.btnSend_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(180, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(309, 21);
            this.label2.TabIndex = 18;
            this.label2.Text = "VD: smtp.gmail.com; smtp.live.com . . .";
            // 
            // MailSender
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(764, 875);
            this.Controls.Add(this.btnSend);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "MailSender";
            this.ShowIcon = false;
            this.Text = "Mail Sender";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lbSmtpsSrver;
        private System.Windows.Forms.Label lbUsername;
        private System.Windows.Forms.Label lbPassword;
        private System.Windows.Forms.Label lbTo;
        private System.Windows.Forms.Label lbSubject;
        private System.Windows.Forms.Label lbFile;
        private System.Windows.Forms.Label lbMessage;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.TextBox txbPassword;
        private System.Windows.Forms.TextBox txbUsername;
        private System.Windows.Forms.TextBox txbSmtpServer;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txbSubject;
        private System.Windows.Forms.TextBox txbFile;
        private System.Windows.Forms.TextBox txbMessage;
        private System.Windows.Forms.TextBox txbTo;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.Button btnMailList;
        private System.Windows.Forms.Button btnAddFile;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton rdListMail;
        private System.Windows.Forms.TextBox txbNhapMail;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

