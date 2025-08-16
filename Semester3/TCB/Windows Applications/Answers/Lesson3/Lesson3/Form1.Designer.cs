namespace Lesson3
{
    partial class Form1
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
            this.CheckDetailsBTN = new System.Windows.Forms.Button();
            this.CheckPaymentBTN = new System.Windows.Forms.Button();
            this.SavePaymentBTN = new System.Windows.Forms.Button();
            this.StudentDetailsGRP = new System.Windows.Forms.GroupBox();
            this.PaymentDetailsGRP = new System.Windows.Forms.GroupBox();
            this.SecondLangCB = new System.Windows.Forms.ComboBox();
            this.FirstLangCB = new System.Windows.Forms.ComboBox();
            this.StudentNameLBL = new System.Windows.Forms.Label();
            this.StudentAgeLBL = new System.Windows.Forms.Label();
            this.StudentNameTB = new System.Windows.Forms.TextBox();
            this.StudentAgeTB = new System.Windows.Forms.TextBox();
            this.CashPayRB = new System.Windows.Forms.RadioButton();
            this.CreditCardPayRB = new System.Windows.Forms.RadioButton();
            this.PaySplitLBL = new System.Windows.Forms.Label();
            this.PaySplitLB = new System.Windows.Forms.ListBox();
            this.ShowStudentsBTN = new System.Windows.Forms.Button();
            this.StudentDetailsGRP.SuspendLayout();
            this.PaymentDetailsGRP.SuspendLayout();
            this.SuspendLayout();
            // 
            // CheckDetailsBTN
            // 
            this.CheckDetailsBTN.Location = new System.Drawing.Point(43, 105);
            this.CheckDetailsBTN.Name = "CheckDetailsBTN";
            this.CheckDetailsBTN.Size = new System.Drawing.Size(129, 38);
            this.CheckDetailsBTN.TabIndex = 0;
            this.CheckDetailsBTN.Text = "Check Details";
            this.CheckDetailsBTN.UseVisualStyleBackColor = true;
            this.CheckDetailsBTN.Click += new System.EventHandler(this.CheckDetailsBTN_Click);
            // 
            // CheckPaymentBTN
            // 
            this.CheckPaymentBTN.Location = new System.Drawing.Point(211, 111);
            this.CheckPaymentBTN.Name = "CheckPaymentBTN";
            this.CheckPaymentBTN.Size = new System.Drawing.Size(135, 38);
            this.CheckPaymentBTN.TabIndex = 0;
            this.CheckPaymentBTN.Text = "Check Payment";
            this.CheckPaymentBTN.UseVisualStyleBackColor = true;
            this.CheckPaymentBTN.Click += new System.EventHandler(this.CheckPaymentBTN_Click);
            // 
            // SavePaymentBTN
            // 
            this.SavePaymentBTN.Enabled = false;
            this.SavePaymentBTN.Location = new System.Drawing.Point(41, 111);
            this.SavePaymentBTN.Name = "SavePaymentBTN";
            this.SavePaymentBTN.Size = new System.Drawing.Size(148, 38);
            this.SavePaymentBTN.TabIndex = 0;
            this.SavePaymentBTN.Text = "Save Payment";
            this.SavePaymentBTN.UseVisualStyleBackColor = true;
            this.SavePaymentBTN.Click += new System.EventHandler(this.SavePaymentBTN_Click);
            // 
            // StudentDetailsGRP
            // 
            this.StudentDetailsGRP.Controls.Add(this.StudentAgeTB);
            this.StudentDetailsGRP.Controls.Add(this.StudentNameTB);
            this.StudentDetailsGRP.Controls.Add(this.StudentNameLBL);
            this.StudentDetailsGRP.Controls.Add(this.StudentAgeLBL);
            this.StudentDetailsGRP.Controls.Add(this.FirstLangCB);
            this.StudentDetailsGRP.Controls.Add(this.SecondLangCB);
            this.StudentDetailsGRP.Controls.Add(this.CheckDetailsBTN);
            this.StudentDetailsGRP.Location = new System.Drawing.Point(78, 34);
            this.StudentDetailsGRP.Name = "StudentDetailsGRP";
            this.StudentDetailsGRP.Size = new System.Drawing.Size(653, 167);
            this.StudentDetailsGRP.TabIndex = 1;
            this.StudentDetailsGRP.TabStop = false;
            this.StudentDetailsGRP.Text = "StudentDetails";
            // 
            // PaymentDetailsGRP
            // 
            this.PaymentDetailsGRP.Controls.Add(this.PaySplitLB);
            this.PaymentDetailsGRP.Controls.Add(this.PaySplitLBL);
            this.PaymentDetailsGRP.Controls.Add(this.CreditCardPayRB);
            this.PaymentDetailsGRP.Controls.Add(this.CashPayRB);
            this.PaymentDetailsGRP.Controls.Add(this.SavePaymentBTN);
            this.PaymentDetailsGRP.Controls.Add(this.CheckPaymentBTN);
            this.PaymentDetailsGRP.Enabled = false;
            this.PaymentDetailsGRP.Location = new System.Drawing.Point(78, 207);
            this.PaymentDetailsGRP.Name = "PaymentDetailsGRP";
            this.PaymentDetailsGRP.Size = new System.Drawing.Size(650, 164);
            this.PaymentDetailsGRP.TabIndex = 2;
            this.PaymentDetailsGRP.TabStop = false;
            this.PaymentDetailsGRP.Text = "PaymentDetails";
            // 
            // SecondLangCB
            // 
            this.SecondLangCB.FormattingEnabled = true;
            this.SecondLangCB.Items.AddRange(new object[] {
            "English",
            "German",
            "Spanish",
            "French",
            "Chinese"});
            this.SecondLangCB.Location = new System.Drawing.Point(43, 38);
            this.SecondLangCB.Name = "SecondLangCB";
            this.SecondLangCB.Size = new System.Drawing.Size(183, 28);
            this.SecondLangCB.TabIndex = 1;
            this.SecondLangCB.Text = "Second Language";
            // 
            // FirstLangCB
            // 
            this.FirstLangCB.FormattingEnabled = true;
            this.FirstLangCB.Items.AddRange(new object[] {
            "English",
            "German",
            "Spanish",
            "French",
            "Chinese"});
            this.FirstLangCB.Location = new System.Drawing.Point(246, 38);
            this.FirstLangCB.Name = "FirstLangCB";
            this.FirstLangCB.Size = new System.Drawing.Size(177, 28);
            this.FirstLangCB.TabIndex = 1;
            this.FirstLangCB.Text = "First Language";
            // 
            // StudentNameLBL
            // 
            this.StudentNameLBL.AutoSize = true;
            this.StudentNameLBL.Location = new System.Drawing.Point(490, 22);
            this.StudentNameLBL.Name = "StudentNameLBL";
            this.StudentNameLBL.Size = new System.Drawing.Size(112, 20);
            this.StudentNameLBL.TabIndex = 3;
            this.StudentNameLBL.Text = "Student Name";
            // 
            // StudentAgeLBL
            // 
            this.StudentAgeLBL.AutoSize = true;
            this.StudentAgeLBL.Location = new System.Drawing.Point(490, 94);
            this.StudentAgeLBL.Name = "StudentAgeLBL";
            this.StudentAgeLBL.Size = new System.Drawing.Size(99, 20);
            this.StudentAgeLBL.TabIndex = 3;
            this.StudentAgeLBL.Text = "Student Age";
            // 
            // StudentNameTB
            // 
            this.StudentNameTB.Location = new System.Drawing.Point(481, 51);
            this.StudentNameTB.Name = "StudentNameTB";
            this.StudentNameTB.Size = new System.Drawing.Size(121, 26);
            this.StudentNameTB.TabIndex = 4;
            // 
            // StudentAgeTB
            // 
            this.StudentAgeTB.Location = new System.Drawing.Point(481, 117);
            this.StudentAgeTB.Name = "StudentAgeTB";
            this.StudentAgeTB.Size = new System.Drawing.Size(121, 26);
            this.StudentAgeTB.TabIndex = 4;
            // 
            // CashPayRB
            // 
            this.CashPayRB.AutoSize = true;
            this.CashPayRB.Location = new System.Drawing.Point(492, 25);
            this.CashPayRB.Name = "CashPayRB";
            this.CashPayRB.Size = new System.Drawing.Size(71, 24);
            this.CashPayRB.TabIndex = 1;
            this.CashPayRB.TabStop = true;
            this.CashPayRB.Text = "Cash";
            this.CashPayRB.UseVisualStyleBackColor = true;
            this.CashPayRB.CheckedChanged += new System.EventHandler(this.CashPayRB_CheckedChanged);
            // 
            // CreditCardPayRB
            // 
            this.CreditCardPayRB.AutoSize = true;
            this.CreditCardPayRB.Location = new System.Drawing.Point(492, 66);
            this.CreditCardPayRB.Name = "CreditCardPayRB";
            this.CreditCardPayRB.Size = new System.Drawing.Size(114, 24);
            this.CreditCardPayRB.TabIndex = 1;
            this.CreditCardPayRB.Text = "Credit Card";
            this.CreditCardPayRB.UseVisualStyleBackColor = true;
            this.CreditCardPayRB.CheckedChanged += new System.EventHandler(this.CreditCardPayRB_CheckedChanged);
            // 
            // PaySplitLBL
            // 
            this.PaySplitLBL.AutoSize = true;
            this.PaySplitLBL.Location = new System.Drawing.Point(383, 29);
            this.PaySplitLBL.Name = "PaySplitLBL";
            this.PaySplitLBL.Size = new System.Drawing.Size(70, 20);
            this.PaySplitLBL.TabIndex = 2;
            this.PaySplitLBL.Text = "Pay Split";
            // 
            // PaySplitLB
            // 
            this.PaySplitLB.Enabled = false;
            this.PaySplitLB.FormattingEnabled = true;
            this.PaySplitLB.ItemHeight = 20;
            this.PaySplitLB.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4"});
            this.PaySplitLB.Location = new System.Drawing.Point(387, 52);
            this.PaySplitLB.Name = "PaySplitLB";
            this.PaySplitLB.Size = new System.Drawing.Size(66, 84);
            this.PaySplitLB.TabIndex = 3;
            // 
            // ShowStudentsBTN
            // 
            this.ShowStudentsBTN.Enabled = false;
            this.ShowStudentsBTN.Location = new System.Drawing.Point(112, 395);
            this.ShowStudentsBTN.Name = "ShowStudentsBTN";
            this.ShowStudentsBTN.Size = new System.Drawing.Size(155, 43);
            this.ShowStudentsBTN.TabIndex = 3;
            this.ShowStudentsBTN.Text = "Show Students";
            this.ShowStudentsBTN.UseVisualStyleBackColor = true;
            this.ShowStudentsBTN.Click += new System.EventHandler(this.ShowStudentsBTN_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ShowStudentsBTN);
            this.Controls.Add(this.PaymentDetailsGRP);
            this.Controls.Add(this.StudentDetailsGRP);
            this.Name = "Form1";
            this.Text = "Form1";
            this.StudentDetailsGRP.ResumeLayout(false);
            this.StudentDetailsGRP.PerformLayout();
            this.PaymentDetailsGRP.ResumeLayout(false);
            this.PaymentDetailsGRP.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button CheckDetailsBTN;
        private System.Windows.Forms.Button CheckPaymentBTN;
        private System.Windows.Forms.Button SavePaymentBTN;
        private System.Windows.Forms.GroupBox StudentDetailsGRP;
        private System.Windows.Forms.TextBox StudentAgeTB;
        private System.Windows.Forms.TextBox StudentNameTB;
        private System.Windows.Forms.Label StudentNameLBL;
        private System.Windows.Forms.Label StudentAgeLBL;
        private System.Windows.Forms.ComboBox FirstLangCB;
        private System.Windows.Forms.ComboBox SecondLangCB;
        private System.Windows.Forms.GroupBox PaymentDetailsGRP;
        private System.Windows.Forms.ListBox PaySplitLB;
        private System.Windows.Forms.Label PaySplitLBL;
        private System.Windows.Forms.RadioButton CreditCardPayRB;
        private System.Windows.Forms.RadioButton CashPayRB;
        private System.Windows.Forms.Button ShowStudentsBTN;
    }
}

