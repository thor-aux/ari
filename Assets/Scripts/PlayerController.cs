using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {

	public float moveSpeed;
	public float jumpForce;
	public CharacterController controller;
	private Vector3 moveDirection;
	public float gravityScale;

	// Use this for initialization
	void Start () {
		controller = GetComponent<CharacterController>();
		moveSpeed = 10f;
		jumpForce = 20f;
		gravityScale = 0.09f;
	}
	
	// Update is called once per frame
	void Update () {
		moveDirection = new Vector3(Input.GetAxis("Horizontal")*moveSpeed,moveDirection.y,Input.GetAxis("Vertical")*moveSpeed);

		if (controller.isGrounded) {
			if (Input.GetButtonDown("Jump")) {
				moveDirection.y = jumpForce;
			}
		}
		moveDirection.y = moveDirection.y+ (Physics.gravity.y * gravityScale);
		controller.Move(moveDirection*Time.deltaTime);
	}
}
