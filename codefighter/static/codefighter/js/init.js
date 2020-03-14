

 $( "#signup_btn" ).click(function() {
   signup_submit()
 });

function signup_submit()
{
  $.ajax({

       url: "/signup_submit",
       type: "POST",
       data: {
         "username" : $("#username_signup_id").val() ,
         "password" : $("#password_signup_id").val() ,
         "email" :  $("#email_signup_id").val() ,
         "phone" :  $("#phone_signup_id").val() ,
         "university" :  $("#university_signup_id").val() ,
         'csrfmiddlewaretoken':"{{ csrf_token }}"
       },

       success: function(response) {

         if(response['result'] == 0){
           M.toast({html:"Invalid Credentials"})
         }
         else{
           M.toast({html:"Verfication Link has been sent to your email address"}, 100000)
           $("#username_signup_id").val("")
           $("#password_signup_id").val("")
           $("#email_signup_id").val("")
           $("#phone_signup_id").val("")
           $("#university_signup_id").val("")
         }
       },
       error: function(xhr, a, b)
       {
         console.log("Some error!");

       }
     });
}


if(window.location.pathname=="/login"){

  $("#nav-practice-id").removeClass("active")
  $("#nav-contest-id").removeClass("active")
  $("#nav-register-id").removeClass("active")
  $("#nav-login-id").addClass("active")
  $("#nav-home-id").removeClass("active")
}

if(window.location.pathname=="/signup"){

  $("#nav-practice-id").removeClass("active")
  $("#nav-contest-id").removeClass("active")
  $("#nav-register-id").addClass("active")
  $("#nav-login-id").removeClass("active")
  $("#nav-home-id").removeClass("active")
}

if(window.location.pathname=="/practice"){

  $("#nav-practice-id").addClass("active")
  $("#nav-contest-id").removeClass("active")
  $("#nav-register-id").removeClass("active")
  $("#nav-login-id").removeClass("active")
  $("#nav-home-id").removeClass("active")
}

if(window.location.pathname=="/"){
  $("#nav-practice-id").removeClass("active")
  $("#nav-contest-id").removeClass("active")
  $("#nav-register-id").removeClass("active")
  $("#nav-login-id").removeClass("active")
  $("#nav-home-id").addClass("active")
}


if(window.location.pathname=="/contests"){
  $("#nav-practice-id").removeClass("active")
  $("#nav-contest-id").addClass("active")
  $("#nav-register-id").removeClass("active")
  $("#nav-login-id").removeClass("active")
  $("#nav-home-id").removeClass("active")
}
